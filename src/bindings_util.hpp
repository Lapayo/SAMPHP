

PHP_FUNCTION(SendClientMessage)
{
	int playerId, color, message_len;
	char *message;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lls", &playerId, &color, &message, &message_len) == FAILURE)
	{
        RETURN_NULL();
    }

    SendClientMessage(playerId, color, message);
}

PHP_FUNCTION(SendClientMessageToAll)
{
	int color, message_len;
	char *message;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ls", &color, &message, &message_len) == FAILURE)
	{
        RETURN_NULL();
    }

    SendClientMessageToAll(color, message);
}

PHP_FUNCTION(SendPlayerMessageToPlayer)
{
	int playerid, senderid, message_len;
	char *message;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lls", &playerid, &senderid, &message, &message_len) == FAILURE)
	{
        RETURN_NULL();
    }

    SendPlayerMessageToPlayer(playerid, senderid, message);
}

PHP_FUNCTION(SendPlayerMessageToAll)
{
	int senderid, message_len;
	char *message;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ls", &senderid, &message, &message_len) == FAILURE)
	{
        RETURN_NULL();
    }

    SendPlayerMessageToAll(senderid, message);
}

PHP_FUNCTION(SendDeathMessage)
{
	int killerId, victimId, weapon;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                         "lll", &killerId, &victimId, &weapon) == FAILURE)
	{
        RETURN_NULL();
    }

    SendDeathMessage(killerId, victimId, weapon);
}

PHP_FUNCTION(GameTextForAll)
{
	char *string;
	int string_len, time, style;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "sll", &string, &string_len, &time, &style) == FAILURE)
	{
        RETURN_NULL();
    }

    GameTextForAll(string, time, style);
}

PHP_FUNCTION(GameTextForPlayer)
{
	int playerid, message_len, time, style;
	char *message;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                         "lsll", &playerid, &message, &message_len, &time, &style) == FAILURE)
	{
        RETURN_NULL();
    }

    GameTextForPlayer(playerid, message, time, style);
}

struct TimerParams
{
	/*zend_fcall_info fci;
	zend_fcall_info_cache fci_cache;
	*/
	zval* callable;
	char* functionName;
	
};

static void SAMPGDK_CALL executeTimedCallback(int timerId, void *voidParams)
{
	/*
	TimerParams *params = (TimerParams *) voidParams;

	zval*** callbackParams;
    zval* retval;

    if (ZEND_FCI_INITIALIZED(params->fci))
    {
		params->fci.retval_ptr_ptr = &retval;
		params->fci.param_count = 0;
		params->fci.params = callbackParams;
		params->fci.no_separation = 0;

		if (zend_call_function(&(params->fci), &(params->fci_cache) TSRMLS_CC) != SUCCESS)
		{
			efree(callbackParams);
			return;
		}
	}
	*/

	TimerParams *params = (TimerParams *) voidParams;

	zval retval;
    zval* callbackParams[] = {  };
	call_user_function(CG(function_table), NULL, params->callable, &retval, 0, callbackParams TSRMLS_CC);
	
}

// TODO Only closures atm :(
PHP_FUNCTION(SetTimer)
{
	TimerParams *params = new TimerParams;
	
	/*
	zend_fcall_info fci = empty_fcall_info;
	zend_fcall_info_cache fci_cache = empty_fcall_info_cache;
	int interval;
	bool repeating;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                         "flb", &(params->fci), &(params->fci_cache), &interval, &repeating) == FAILURE)
	{
        RETURN_NULL();
    }

    if(ZEND_FCI_INITIALIZED(params->fci))
    {
		params->fci.no_separation = 1;
	}
	*/

	zval* callable;
	int interval;
	bool repeating;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                         "olb", &callable, &interval, &repeating) == FAILURE)
	{
        RETURN_NULL();
    }

    Z_ADDREF_P(callable);
    params->callable = callable;
    
	
	int ret = SetTimer(interval, repeating, executeTimedCallback, (void*) params);
	
    RETVAL_LONG(ret);

}

PHP_FUNCTION(KillTimer)
{
	int timerId;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                         "l", &timerId) == FAILURE)
	{
        RETURN_NULL();
    }

    KillTimer(timerId);
}

PHP_FUNCTION(GetTickCount)
{
	int count = GetTickCount();

    RETVAL_LONG(count);
}

PHP_FUNCTION(GetMaxPlayers)
{
    RETVAL_LONG(GetMaxPlayers());
}