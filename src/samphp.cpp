#include "bindings.h"
#include "samphp.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

int php_set_ini_entry(char *entry, char *value, int stage)
{
	return zend_alter_ini_entry(entry, strlen(entry)+1, value, strlen(value)+1, PHP_INI_USER, stage);
}

samphp *samphp::instance = NULL;

using sampgdk::logprintf;

samphp::samphp(bool typeError)
{
	int argc = 1;
	char *argv[2] = { "samp03svr", NULL };

	php_embed_module.ub_write = samphp_output_handler;
	php_embed_module.sapi_error = &samphp::error_wrap;
	php_embed_module.log_message = samphp_error_handler;
	php_embed_init(argc, argv PTSRMLS_CC);

	zend_alter_ini_entry("html_errors", 12, "0", 1, PHP_INI_SYSTEM, PHP_INI_STAGE_ACTIVATE);
	zend_alter_ini_entry("implicit_flush", 15, "1", 1, PHP_INI_SYSTEM, PHP_INI_STAGE_ACTIVATE);
	zend_alter_ini_entry("max_execution_time", 19, "0", 1, PHP_INI_SYSTEM, PHP_INI_STAGE_ACTIVATE);
	zend_alter_ini_entry("variables_order", 16, "S", 1, PHP_INI_SYSTEM, PHP_INI_STAGE_ACTIVATE);
	
	SG(options) |= SAPI_OPTION_NO_CHDIR;
	SG(headers_sent) = 1;
	SG(request_info).no_headers = 1;
	PG(during_request_startup) = 0;

	php_set_ini_entry("max_execution_time", "0", PHP_INI_STAGE_ACTIVATE);
	zend_unset_timeout(TSRMLS_C);

	php_set_ini_entry("variables_order", "S", PHP_INI_STAGE_ACTIVATE);
	
	#ifdef ZEND_WIN32
		php_set_ini_entry("include_path", ".;./php", PHP_INI_SYSTEM);
	#else
		php_set_ini_entry("include_path", ".:./php", PHP_INI_SYSTEM);
	#endif
}

samphp::~samphp()
{
	php_embed_shutdown(TSRMLS_CC);
}

void samphp::unload()
{
	delete samphp::instance;
	samphp::instance = NULL;
}

samphp* samphp::init()
{
	samphp* instance = new samphp(true);

	zend_startup_module(&samphp_module_entry);

	samphp::instance = instance;
	
	return instance;
}

bool samphp::loadGamemode()
{
	std::string gamemode = GetServerCfgOption("samphpmode");
	
	if(gamemode.length() > 0)
	{
		gamemode = "php/" + gamemode + "/gamemode.php";
	}else{
		gamemode = "php/gamemode.php";
	}

	zend_first_try {
		char *filename = (char *) gamemode.c_str();
		char *include_script;
		spprintf(&include_script, 0, "require '%s';", filename);
		zend_eval_string(include_script, NULL, filename TSRMLS_CC);
		efree(include_script);
	} zend_end_try();

	return true;
}

bool samphp::callBool(char *fn, char *argspec, ...)
{
	bool rrv = false;

	zval *rv;

	va_list ap;
	va_start(ap, argspec);
	rv = call(fn, argspec, ap TSRMLS_CC);
	va_end(ap);

	if(rv)
	{
		if(Z_TYPE_P(rv) != IS_BOOL)
		{
			// copy rv into new memory for the in place conversion
			zval *cp;
			MAKE_STD_ZVAL(cp);
			*cp = *rv;
			zval_copy_ctor(cp);
			INIT_PZVAL(cp);

			// destroy the original now that we have a copy
			zval_ptr_dtor(&rv);

			// rename rv to our copy
			rv = cp;
			convert_to_boolean_ex(&rv);
		}

		rrv = (bool)Z_LVAL_P(rv);
		zval_ptr_dtor(&rv);
	}

	return rrv;
}

zval *samphp::call(char *fn, char *argspec, va_list ap TSRMLS_DC)
{
	zval *rrv = NULL;

	zend_try {
		// convert the function name to a zval
		zval *function_name;
		MAKE_STD_ZVAL(function_name);
		ZVAL_STRING(function_name, fn, 0);

		// parse the parameter list
		zval **params = NULL;
		int len = strlen(argspec);

		if(len > 0)
			params = new zval* [strlen(argspec)];

		zend_uint count;
		if (parse_args(params, &count, argspec, ap) != SUCCESS)
		{
			error_wrap(0, "Error parsing args for function %s", fn);

			for(unsigned int i = 0; i < count; i++)
				if(params[i]) zval_ptr_dtor(&params[i]);
			efree(function_name);
			status = FAIL;
		}

		if(status != FAIL){
			zval *rv;
			MAKE_STD_ZVAL(rv);
			if(call_user_function(EG(function_table), NULL, function_name, rv,
														count, params TSRMLS_CC) != SUCCESS)
			{
				error_wrap(0, "calling function %s\n", fn);

				for(unsigned int i = 0; i < count; i++)
					if(params[i]) zval_ptr_dtor(&params[i]);
				efree(function_name);
				status = FAIL;
			}

			if(status != FAIL){
				for(unsigned int i = 0; i < count; i++)
					if(params[i]) zval_ptr_dtor(&params[i]);
				efree(function_name);
				rrv = rv;
			}
		}

		delete params;
	} zend_catch {
		error_wrap(0, "preparing function %s\n", fn);
		status = FAIL;
	} zend_end_try() {
	}


	return rrv;
}

void samphp::error_wrap(int error, const char * fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);

	char *dummy = NULL;
	int size = vsnprintf(dummy, 0, fmt, ap);

	va_end(ap);
	va_start(ap, fmt);

	char *buffer = new char[size + 1];
	int ret = vsnprintf(buffer, size + 1, fmt, ap);

	va_end(ap);

	// give up if we failed to allocate a proper buffer
	if(ret < size)
		return;

	internal_error(buffer);
}

php_ret samphp::parse_args(zval **params, zend_uint *count, char *argspec, va_list ap)
{
  int i = 0;
  for(char *trav = argspec; *trav; trav++)
  {
    MAKE_STD_ZVAL(params[i]);
    switch(*trav)
    {
    case 'b':
      {
        // va promotes bools to ints
        int arg = va_arg(ap, int);
        ZVAL_BOOL(params[i], arg);
      }
      break;

    case 'i':
      {
        int arg = va_arg(ap, int);
        ZVAL_LONG(params[i], arg);
      }
      break;

    case 'l':
      {
        long arg = va_arg(ap, long);
        ZVAL_LONG(params[i], arg);
      }
      break;

    case 'd':
      {
        double arg = va_arg(ap, double);
        ZVAL_DOUBLE(params[i], arg);
      }
      break;

    case 's':
      {
        char *arg = va_arg(ap, char *);
        ZVAL_STRING(params[i], arg, 1);
      }
      break;

    case 'S':
      {
        char *arg = va_arg(ap, char *);
        unsigned int binStrLen = va_arg(ap, unsigned int);
        ZVAL_STRINGL(params[i], arg, binStrLen, 1);
      }
      break;

    default:
      status = FAIL;
      return status;
    }

    i++;
  }

  *count = i;

  return SUCCESS;
}

void samphp::internal_error(const char *str)
{
	samphp_error_handler((char*) str);
}



int samphp_output_handler(const char *str, unsigned int str_length)
{
	logprintf(str);
	return str_length;
}

void samphp_error_handler(char *str)
{
	logprintf(str);
}



// Created by: https://github.com/Zeex/sampgdk/blob/master/plugins/unlimitedfs/unlimitedfs.cpp
std::string GetServerCfgOption(const std::string &option)
{
	std::string name, value;
	std::string line;
	std::fstream server_cfg("server.cfg");
	if(server_cfg)
	{
		while(std::getline(server_cfg, line))
		{
			std::stringstream ss(line);
			ss >> name;
			if (name == option)
			{
				ss >> value;
				break;
			}
		}
  }
  return value;
}

/*
void samphp_output_handler(const char *str)
{
	ServerLog::Printf(str);
	//std::cout << str << std::endl;
}
*/
/*
void samphp_init()
{
	int argc = 1;
	char *argv[2] = { "samp03svr", NULL };

	php_embed_module.ub_write = samphp_output_handler;
	php_embed_init(argc, argv PTSRMLS_CC);
	zend_startup_module(&samphp_module_entry);
}

void samphp_shutdown()
{
	php_embed_shutdown(TSRMLS_CC);
}

void samphp_execute(char *filename)
{
	zend_first_try {
		char *include_script;
		spprintf(&include_script, 0, "include '%s'", filename);
		zend_eval_string(include_script, NULL, filename TSRMLS_CC);
		efree(include_script);
	} zend_end_try();
}

int samphp_output_handler(const char *str, unsigned int str_length TSRMLS_DC)
{
	ServerLog::Printf(str);
	return str_length;
}

void samphp_call(std::string functionName, )
*/
