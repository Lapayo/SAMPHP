PHP_FUNCTION(CallAMXNative)
{
	int argc = ZEND_NUM_ARGS();
    zval **args;

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
	
	std::cout << "calling function " << function_name << " with return type " << function_return << std::endl;


	if(argc > 2)
	{
		convert_to_string(args[2]);
		if(Z_STRLEN_P(args[2]) > 0)
		{
			const char *parameter_descriptors = Z_STRVAL_P(args[2]);
			
			int pd_i = 0;
			for(int p_i = 3; p_i < argc; p_i++)
			{
				zval *val = args[p_i];
			
				switch(parameter_descriptors[pd_i])
				{
				case 's':
					convert_to_string(val);
					std::cout << "Pushing string: " << Z_STRVAL_P(val) << std::endl;
					break;
				case 'b':
				case 'i':
				case 'l':
					convert_to_long(val);
					std::cout << "Pushing Integer: " << Z_LVAL_P(val) << std::endl;
					break;
				case 'd':
				case 'f':
					convert_to_double(val);
					std::cout << "Pushing float: " << static_cast<float>(Z_DVAL_P(val)) << std::endl;
					break;
				case 'u':	// String reference object
				case 'v':	//Float reference
					std::cout << "Pushing reference" << std::endl;
					break;
				default:
					efree(args);

					std::cerr << "UNKNOWN DESCRIPTOR: " << parameter_descriptors[pd_i] << std::endl;

					RETURN_BOOL(false);
					break;
				}

				pd_i++;
			}
		}
	}

   
    efree(args);
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