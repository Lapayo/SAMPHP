PLUGIN_EXPORT bool PLUGIN_CALL OnGameModeInit()
{
	samphp::init()->loadGamemode();

	return samphp::instance->callBool("OnGameModeInit");
}

PLUGIN_EXPORT bool PLUGIN_CALL OnGameModeExit()
{
	bool result = samphp::instance->callBool("OnGameModeExit");

	samphp::unload();

	return result;
}

PLUGIN_EXPORT bool PLUGIN_CALL OnFilterScriptInit()
{
	return samphp::instance->callBool("OnFilterScriptInit");
}

PLUGIN_EXPORT bool PLUGIN_CALL OnFilterScriptExit()
{
	return samphp::instance->callBool("OnFilterScriptExit");
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerConnect(int playerid)
{
	return samphp::instance->callBool("OnPlayerConnect", "l", playerid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerDisconnect(int playerid, int reason)
{
	return samphp::instance->callBool("OnPlayerDisconnect", "ll", playerid, reason);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerSpawn(int playerid)
{
	return samphp::instance->callBool("OnPlayerSpawn", "l", playerid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerDeath(int playerid, int killerid, int reason)
{
	return samphp::instance->callBool("OnPlayerDeath", "lll", playerid, killerid, reason);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnVehicleSpawn(int vehicleid)
{
	return samphp::instance->callBool("OnVehicleSpawn", "l", vehicleid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnVehicleDeath(int vehicleid, int killerid)
{
	return samphp::instance->callBool("OnVehicleDeath", "ll", vehicleid, killerid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerText(int playerid, const char *text)
{
	return samphp::instance->callBool("OnPlayerText", "ls", playerid, text);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerCommandText(int playerid, const char *cmdtext)
{
	return samphp::instance->callBool("OnPlayerCommandText", "ls", playerid, cmdtext);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerRequestClass(int playerid, int classid)
{
	return samphp::instance->callBool("OnPlayerRequestClass", "ll", playerid, classid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerEnterVehicle(int playerid, int vehicleid, bool ispassenger)
{
	return samphp::instance->callBool("OnPlayerEnterVehicle", "llb", playerid, vehicleid, ispassenger);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerExitVehicle(int playerid, int vehicleid)
{
	return samphp::instance->callBool("OnPlayerExitVehicle", "ll", playerid, vehicleid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerStateChange(int playerid, int newstate, int oldstate)
{
	return samphp::instance->callBool("OnPlayerStateChange", "lll", playerid, newstate, oldstate);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerEnterCheckpoint(int playerid)
{
	return samphp::instance->callBool("OnPlayerEnterCheckpoint", "l", playerid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerLeaveCheckpoint(int playerid)
{
	return samphp::instance->callBool("OnPlayerLeaveCheckpoint", "l", playerid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerEnterRaceCheckpoint(int playerid)
{
	return samphp::instance->callBool("OnPlayerEnterRaceCheckpoint", "l", playerid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerLeaveRaceCheckpoint(int playerid)
{
	return samphp::instance->callBool("OnPlayerLeaveRaceCheckpoint", "l", playerid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnRconCommand(const char *cmd)
{
	return samphp::instance->callBool("OnRconCommand", "s", cmd);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerRequestSpawn(int playerid)
{
	return samphp::instance->callBool("OnPlayerRequestSpawn", "l", playerid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnObjectMoved(int objectid)
{
	return samphp::instance->callBool("OnObjectMoved", "l", objectid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerObjectMoved(int playerid, int objectid)
{
	return samphp::instance->callBool("OnPlayerObjectMoved", "ll", playerid, objectid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerPickUpPickup(int playerid, int pickupid)
{
	return samphp::instance->callBool("OnPlayerPickUpPickup", "ll", playerid, pickupid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnVehicleMod(int playerid, int vehicleid, int componentid)
{
	return samphp::instance->callBool("OnVehicleMod", "lll", playerid, vehicleid, componentid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnEnterExitModShop(int playerid, int enterexit, int interiorid)
{
	return samphp::instance->callBool("OnEnterExitModShop", "lll", playerid, enterexit, interiorid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnVehiclePaintjob(int playerid, int vehicleid, int paintjobid)
{
	return samphp::instance->callBool("OnVehiclePaintjob", "lll", playerid, vehicleid, paintjobid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnVehicleRespray(int playerid, int vehicleid, int color1, int color2)
{
	return samphp::instance->callBool("OnVehicleRespray", "llll", playerid, vehicleid, color1, color2);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnVehicleDamageStatusUpdate(int vehicleid, int playerid)
{
	return samphp::instance->callBool("OnVehicleDamageStatusUpdate", "ll", vehicleid, playerid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnUnoccupiedVehicleUpdate(int vehicleid, int playerid, int passenger)
{
	return samphp::instance->callBool("OnUnoccupiedVehicleUpdate", "lll", vehicleid, playerid, passenger);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerSelectedMenuRow(int playerid, int row)
{
	return samphp::instance->callBool("OnPlayerSelectedMenuRow", "ll", playerid, row);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerExitedMenu(int playerid)
{
	return samphp::instance->callBool("OnPlayerExitedMenu", "l", playerid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerInteriorChange(int playerid, int newinteriorid, int oldinteriorid)
{
	return samphp::instance->callBool("OnPlayerInteriorChange", "lll", playerid, newinteriorid, oldinteriorid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerKeyStateChange(int playerid, int newkeys, int oldkeys)
{
	return samphp::instance->callBool("OnPlayerKeyStateChange", "lll", playerid, newkeys, oldkeys);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnRconLoginAttempt(const char *ip, const char *password, bool success)
{
	return samphp::instance->callBool("OnRconLoginAttempt", "ssb", ip, password, success);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerUpdate(int playerid)
{
	return samphp::instance->callBool("OnPlayerUpdate", "l", playerid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerStreamIn(int playerid, int forplayerid)
{
	return samphp::instance->callBool("OnPlayerStreamIn", "ll", playerid, forplayerid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerStreamOut(int playerid, int forplayerid)
{
	return samphp::instance->callBool("OnPlayerStreamOut", "ll", playerid, forplayerid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnVehicleStreamIn(int vehicleid, int forplayerid)
{
	return samphp::instance->callBool("OnVehicleStreamIn", "ll", vehicleid, forplayerid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnVehicleStreamOut(int vehicleid, int forplayerid)
{
	return samphp::instance->callBool("OnVehicleStreamOut", "ll", vehicleid, forplayerid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnDialogResponse(int playerid, int dialogid, int response, int listitem, const char *inputtext)
{
	return samphp::instance->callBool("OnDialogResponse", "lllls", playerid, dialogid, response, listitem, inputtext);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerTakeDamage(int playerid, int issuerid, float amount, int weaponid)
{
	return samphp::instance->callBool("OnPlayerTakeDamage", "lldl", playerid, issuerid, amount, weaponid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerGiveDamage(int playerid, int damagedid, float amount, int weaponid)
{
	return samphp::instance->callBool("OnPlayerGiveDamage", "lldl", playerid, damagedid, amount, weaponid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerClickMap(int playerid, float fX, float fY, float fZ)
{
	return samphp::instance->callBool("OnPlayerClickMap", "lddd", playerid, fX, fY, fZ);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerClickPlayer(int playerid, int clickedplayerid, int source)
{
	return samphp::instance->callBool("OnPlayerClickPlayer", "lll", playerid, clickedplayerid, source);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerEditObject(int playerid, bool playerobject, int objectid, int response, float fX, float fY, float fZ, float fRotX, float fRotY, float fRotZ)
{
	return samphp::instance->callBool("OnPlayerEditObject", "lblldddddd", playerid, playerobject, objectid, response, fX, fY, fZ, fRotX, fRotY, fRotZ);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerEditAttachedObject(int playerid, int response, int index, int modelid, int boneid, float fOffsetX, float fOffsetY, float fOffsetZ, float fRotX, float fRotY, float fRotZ, float fScaleX, float fScaleY, float fScaleZ)
{
	return samphp::instance->callBool("OnPlayerEditAttachedObject", "lllllddddddddd", playerid, response, index, modelid, boneid, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ, fScaleX, fScaleY, fScaleZ);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerSelectObject(int playerid, int type, int objectid, int modelid, float fX, float fY, float fZ)
{
	return samphp::instance->callBool("OnPlayerSelectObject", "llllddd", playerid, type, objectid, modelid, fX, fY, fZ);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerClickTextDraw(int playerid, int clickedid)
{
	return samphp::instance->callBool("OnPlayerClickTextDraw", "ll", playerid, clickedid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerClickPlayerTextDraw(int playerid, int playertextid)
{
	return samphp::instance->callBool("OnPlayerClickPlayerTextDraw", "ll", playerid, playertextid);
}
