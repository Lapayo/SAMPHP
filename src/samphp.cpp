#include "samphp.h"
#include "bindings.h"
#include <string>
#include <iostream>

samphp *samphp::instance = NULL;

samphp::samphp(bool typeError)
    : php_stl(typeError)
{

}

samphp* samphp::reload()
{
    std::string loadedFile = samphp::instance->loadedFile;
    delete samphp::instance;

    samphp::init()->load(loadedFile);
}

samphp* samphp::init()
{
    samphp* instance = new samphp(true);

    zend_startup_module(&samphp_module_entry);

    samphp::instance = instance;


    
    instance->set_message_function(samphp_output_handler);
    instance->set_output_function(samphp_output_handler);
    instance->set_error_function(samphp_output_handler);

    return instance;
}

bool samphp::load(std::string file)
{
    this->loadedFile = file;

    return php_stl::load(file.c_str());
}

void samphp_output_handler(const char *str)
{
    ServerLog::Printf(str);
    //std::cout << str << std::endl;
}

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