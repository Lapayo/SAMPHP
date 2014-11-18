#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <string>
#include <sapi/embed/php_embed.h>
#include "samphp.h"

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() {
	sampgdk::logprintf("  *****************************************************");
	sampgdk::logprintf("  *          SAMPHP Plugin revision 2.0B              *");
	sampgdk::logprintf("  *             WITHOUT: AMX Handlers                 *");
	sampgdk::logprintf("  * For updates, check out our GitHub repository at : *");
	sampgdk::logprintf("  *     https ://github.com/Lapayo/SAMPHP             *");
	sampgdk::logprintf("  *****************************************************");
	return sampgdk::Supports() | SUPPORTS_PROCESS_TICK;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData) {
	return sampgdk::Load(ppData);
}

PLUGIN_EXPORT void PLUGIN_CALL Unload() {
	samphp::unload();
	sampgdk::Unload();
}

PLUGIN_EXPORT void PLUGIN_CALL ProcessTick() {
  sampgdk::ProcessTick();
}
