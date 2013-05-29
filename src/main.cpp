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
  samphp::init();

  bool result = samphp_plugin.Load(ppData) >= 0;

  /*
  TODO: Bug in sampgdk
  const int buffer_len = 100;
  char buffer[buffer_len];

  GetServerVarAsString("hostname", buffer, buffer_len);

  std::cout << "Samphp: " << buffer << std::endl;
  */
  
  samphp::instance->load("php/gamemode.php");


  return result;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
  delete samphp::instance;
  samphp_plugin.Unload();
}

PLUGIN_EXPORT void PLUGIN_CALL ProcessTick()
{
  samphp_plugin.ProcessTimers();
}
