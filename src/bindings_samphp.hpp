#include <fakeamx.h>
#include <cstring>

AMX_NATIVE FindNative(const char *name);

#define ARG_OFFSET 3
PHP_FUNCTION(CallAMXNative)
{
	int argc = ZEND_NUM_ARGS();
    zval **args;
	FakeAmx &fakeamx = FakeAmx::GetInstance();

    args = (zval **)safe_emalloc(argc, sizeof(zval *), 0);
    
    if(argc < 2 ||
        zend_get_parameters_array(argc, argc, args) == FAILURE)
    {
        efree(args);
        WRONG_PARAM_COUNT;
    }
	
	convert_to_string(args[0]);
	convert_to_string(args[1]);

	const char *function_name = Z_STRVAL_P(args[0]);
	const char *function_return = Z_STRVAL_P(args[1]);
	
	AMX_NATIVE native = FindNative(function_name);
	
	if(native == 0)
	{
        efree(args);
		std::cerr << "Native not found: " << function_name << std::endl;
		RETURN_BOOL(false);
	}

	cell *params = NULL;
	const char *parameter_descriptors = NULL;
	int num_descriptors = 0;

	if(argc > 2)
	{
		convert_to_string(args[2]);
		if(Z_STRLEN_P(args[2]) > 0)
		{
			num_descriptors = argc - ARG_OFFSET;
			parameter_descriptors = Z_STRVAL_P(args[2]);

			params = new cell[Z_STRLEN_P(args[2]) + 1];
			params[0] = Z_STRLEN_P(args[2]) * sizeof(cell);
			
			int pd_i = 0;
			for(int p_i = ARG_OFFSET; p_i < argc; p_i++)
			{
				zval *val = args[p_i];
			
				switch(parameter_descriptors[pd_i])
				{
				case 's':
					convert_to_string(val);					
					params[pd_i + 1] = fakeamx.Push(Z_STRVAL_P(val));
					break;
				case 'l':
					convert_to_long(val);
					params[pd_i + 1] = (cell) Z_LVAL_P(val);
					break;
				case 'd':
					convert_to_double(val);
					params[pd_i + 1] = amx_ftoc(Z_DVAL_P(val));

					break;
				case 'u':	// String reference object
				{
					//get buffer size from next param:
					zval *size_val = args[p_i + 1];
					convert_to_long(size_val);
					int size = Z_LVAL_P(size_val);
					// Push size cells as a buffer
					params[pd_i + 1] = fakeamx.Push(size);
					break;
				}
				case 'v':	//Float reference
					//push 1 cell for the float
					params[pd_i + 1] = fakeamx.Push(1);
					break;
				case 'w':
					//push 1 cell for the integer
					params[pd_i + 1] = fakeamx.Push(1);
					break;
				default:
					efree(args);
					delete params;

					std::cerr << "UNKNOWN DESCRIPTOR: " << parameter_descriptors[pd_i] << std::endl;

					RETURN_BOOL(false);
					break;
				}

				pd_i++;
			}
		}
	}
	//Call function
	cell retval = fakeamx.CallNative(native, params);
	
	// Clean up and reference hydration
	for(int i = 0; i < num_descriptors; i++)
	{
		switch(parameter_descriptors[i])
		{
		case 's':
			fakeamx.Pop(params[i + 1]);
			break;
		case 'u':
		{
			zval *ref = args[ARG_OFFSET + i];
			int size = (int) params[i + 2];
			
			char *buffer = new char[size];

			fakeamx.Get(params[i + 1], buffer, size);
			fakeamx.Pop(params[i + 1]);

			convert_to_null(ref);
			
			ZVAL_STRING(ref, buffer, true);
			delete buffer;
			break;
		}
		case 'v':
		{
			zval *ref = args[ARG_OFFSET + i];
			float tmp;
			cell retval;
			fakeamx.Get(params[i + 1], retval);
			fakeamx.Pop(params[i + 1]);

			tmp = amx_ctof(retval);

			convert_to_null(ref);
			ZVAL_DOUBLE(ref, tmp);
			
			break;
		}
		case 'w':
		{
			zval *ref = args[ARG_OFFSET + i];
			int tmp;
			cell retval;
			fakeamx.Get(params[i + 1], retval);
			fakeamx.Pop(params[i + 1]);

			tmp = (int) retval;
	
			convert_to_null(ref);
			ZVAL_LONG(ref, tmp);
			
			break;
		}
		}
	}


	
	// Return value
	char ret_type = function_return[0];

    efree(args);
	delete params;

	switch(ret_type)
	{
	case 'l':
		RETURN_LONG(retval);
	case 'd':
		RETURN_DOUBLE(amx_ctof(retval));
	case 'n':
		RETURN_NULL();

	case 's':
		
	default:
		std::cerr << "UNKNOWN RETURN TYPE: " << ret_type << std::endl;

		RETURN_BOOL(false);
		break;
	}
   
}

PHP_FUNCTION(AMXNativeExists)
{
    char *name;
	int name_len;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "s", &name, &name_len) == FAILURE)
    {
        RETURN_NULL();
    }

	RETURN_BOOL(FindNative(name) != 0);
}


PHP_FUNCTION(DebugFunction)
{
	zend_fcall_info fci = empty_fcall_info;
	zend_fcall_info_cache fci_cache = empty_fcall_info_cache;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                         "f", &fci, &fci_cache) == FAILURE)
	{
        RETURN_NULL();
    }

	zval*** params = NULL;
    zval *retval;

    if (ZEND_FCI_INITIALIZED(fci))
    {
		fci.retval_ptr_ptr = &retval;
		fci.param_count = 0;
		fci.params = params;
		fci.no_separation = 0;

		if (zend_call_function(&fci, &fci_cache TSRMLS_CC) != SUCCESS)
		{
			zval_dtor(return_value);
			efree(params);
			RETURN_NULL();
		}


	}

}

// Thx to zeex
AMX_NATIVE FindNative(const char *name)
{
    const AMX_NATIVE_INFO *natives = sampgdk_get_natives();
    int num_natives = sampgdk_num_natives();

    for (int i = 0; i < num_natives; i++) {
        if (std::strcmp(natives[i].name, name) == 0) {
            return natives[i].func;
        }
    }

    return 0;
}