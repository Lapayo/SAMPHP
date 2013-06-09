PHP_FUNCTION(testings)
{
	int argc = ZEND_NUM_ARGS();
    zval **args;

    args = (zval **)safe_emalloc(argc, sizeof(zval *), 0);
    
    if(argc < 1 ||
        zend_get_parameters_array(argc, 1, args) == FAILURE)
    {
        efree(args);
        WRONG_PARAM_COUNT;
    }

    for(int i = 0; i < argc; i++)
    {
        std::cout << args[i]->type << std::endl;;
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