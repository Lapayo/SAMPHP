#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>

#include "samphp.h"

static ThisPlugin samphp_plugin;


PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
	return SUPPORTS_VERSION | SUPPORTS_PROCESS_TICK;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData)
{
	return samphp_plugin.Load(ppData) >= 0;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
	samphp::unload();
	samphp_plugin.Unload();
}

PLUGIN_EXPORT void PLUGIN_CALL ProcessTick()
{
	samphp_plugin.ProcessTimers();
}
