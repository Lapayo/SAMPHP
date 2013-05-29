<?php
$callbackList = file_get_contents(__DIR__."/callbacks.txt");
$callbackList = array_map(function($line) {
	return trim($line);
}, explode("\n", $callbackList));

function OnDialogResponse($playerid, $dialogid, $response, $listitem, $inputtext)
{
	return Event::until("DialogResponse", false, Player::find($playerid, true), $dialogid, $response, $listitem, $inputtext);
}

function OnEnterExitModShop($playerid, $enterexit, $interiorid)
{
	return Event::until("EnterExitModShop", true, Player::find($playerid, true), $enterexit, $interiorid);
}

function OnGameModeExit()
{
	return Event::until("GameModeExit");
}

function OnGameModeInit() 
{
	return Event::until("GameModeInit");
}

function OnObjectMoved($objectid)
{
	return Event::until("ObjectMoved");
}

function OnPlayerClickMap($playerid, $fx, $fy, $fz)
{
	return Event::until("PlayerClickMap", true, Player::find($playerid, true), $fx, $fy, $fz);
}

function OnPlayerClickPlayer($playerid, $clickedplayerid, $source)
{
	return Event::until("PlayerClickPlayer", true, Player::find($playerid, true), $clickedplayerid, $source);
}

function OnPlayerClickPlayerTextDraw($playerid, $playertextid)
{
	return Event::until("PlayerClickPlayerTextDraw", false, Player::find($playerid, true), $playertextid);
}

function OnPlayerClickTextDraw($playerid, $clickedid)
{
	return Event::until("PlayerClickTextDraw", false, Player::find($playerid, true), $clickedid);
}

function OnPlayerCommandText($playerid, $cmdtext)
{
	return Event::until("PlayerCommandText", false, Player::find($playerid, true), $cmdtext);
}

function OnPlayerConnect($playerid)
{
	return Event::until("PlayerConnect", true, Player::find($playerid, true));
}

function OnPlayerDeath($playerid, $killerid, $reason)
{
	return Event::until("PlayerDeath", true, Player::find($playerid, true), $killerid, $reason);
}

function OnPlayerDisconnect($playerid, $reason)
{
	return Event::until("PlayerDisconnect", true, Player::find($playerid, true), $reason);
}

function OnPlayerEditAttachedObject($playerid, $response, $index, $modelid, $boneid, $fOffsetX, $fOffsetY, $fOffsetZ, $fRotX, $fRotY, $fRotZ, $fScaleX, $fScaleY, $fScaleZ)
{
	return Event::until("PlayerEditAttachedObject", true, Player::find($playerid, true), $response, $index, $modelid, $boneid, $fOffsetX, $fOffsetY, $fOffsetZ, $fRotX, $fRotY, $fRotZ, $fScaleX, $fScaleY, $fScaleZ);
}

function OnPlayerEditObject($playerid,	$playerobject,	$objectid,	$response,	$fX,	$fY,	$fZ,	$fRotX,	$fRotY,	$fRotZ)
{
	return Event::fireDefault(Player::find($playerid, true), true, $playerobject, $objectid,	$response,	$fX,	$fY,	$fZ,	$fRotX,	$fRotY,	$fRotZ);
}

function OnPlayerEnterCheckpoint($playerid)
{
	return Event::fireDefault("PlayerEnterCheckpoint", true, Player::find($playerid, true));
}

function OnPlayerEnterRaceCheckpoint($playerid)
{
	return Event::fireDefault("PlayerEnterCheckpoint", true, Player::find($playerid, true));
}

function OnPlayerEnterVehicle($playerid, $vehicleid, $passenger)
{
	return Event::until("PlayerEnterVehicle", true, Player::find($playerid, true), Vehicle::find($vehicleid), $passenger);
}

function OnPlayerExitVehicle($playerid, $vehicleid)
{
	return Event::fireDefault("PlayerExitVehicle", true, Player::find($playerid, true), Vehicle::find($vehicleid));
}

function OnPlayerExitedMenu($playerid)
{
	return Event::fireDefault("PlayerExitedMenu", true, Player::find($playerid, true));
}

function OnPlayerGiveDamage($playerid, $damagedid, $amount, $weaponid)
{
	return Event::fireDefault("PlayerGiveDamage", true, Player::find($playerid, true), $damagedid, $amount, $weaponid);
}

function OnPlayerInteriorChange($playerid, $newinteriorid, $oldinteriorid)
{
	return Event::fireDefault("PlayerInteriorChange", true, Player::find($playerid, true), $newinteriorid, $oldinteriorid);
}

function OnPlayerKeyStateChange($playerid, $newkeys, $oldkeys)
{
	return Event::fireDefault("PlayerKeyStateChange", true, Player::find($playerid, true), $newkeys, $oldkeys);
}

function OnPlayerLeaveCheckpoint($playerid)
{
	return Event::fireDefault("PlayerLeaveCheckpoint", true, Player::find($playerid, true));
}

function OnPlayerLeaveRaceCheckpoint($playerid)
{
	return Event::fireDefault("PlayerLeaveRaceCheckpoint", true, Player::find($playerid, true));
}

function OnPlayerObjectMoved($playerid, $objectid)
{
	return Event::fireDefault("PlayerObjectMoved", true, Player::find($playerid, true), $objectid);
}

function OnPlayerPickUpPickup($playerid, $pickupid)
{
	return Event::fireDefault("PlayerPickUpPickup", true, Player::find($playerid, true), $pickupid);
}

function OnPlayerPrivmsg($playerid, $recieverid, $text)
{
	return Event::until("PlayerPrivmsg", true, Player::find($playerid, true), Player::find($recieverid, true), $text);
}

function OnPlayerRequestClass($playerid, $classid)
{
	return Event::until("PlayerRequestClass", true, Player::find($playerid, true), $classid);
}

function OnPlayerRequestSpawn($playerid)
{
	return Event::until("PlayerRequestSpawn", true, Player::find($playerid, true));
}

function OnPlayerSelectObject($playerid, $type, $objectid, $modelid, $fX, $fY, $fZ)
{
	return Event::fireDefault("PlayerSelectObject", true, Player::find($playerid, true), $type, $objectid, $modelid, $fX, $fY, $fZ);
}

function OnPlayerSelectedMenuRow($playerid, $row)
{
	return Event::fireDefault("PlayerSelectedMenuRow", true, Player::find($playerid, true), $row);
}

function OnPlayerSpawn($playerid)
{
	return Event::fireDefault("PlayerSpawn", true, Player::find($playerid, true));
}

function OnPlayerStateChange($playerid, $newstate, $oldstate)
{
	return Event::fireDefault("PlayerStateChange", true, Player::find($playerid, true), $newstate, $oldstate);
}

function OnPlayerStreamIn($playerid, $forplayerid)
{
	return Event::fireDefault("PlayerStreamIn", true, Player::find($playerid, true), Player::find($forplayerid, true));
}

function OnPlayerStreamOut($playerid, $forplayerid)
{
	return Event::fireDefault("PlayerStreamOut", true, Player::find($playerid, true), Player::find($forplayerid, true));
}

function OnPlayerTakeDamage($playerid, $issuerid, $amount, $weaponid)
{
	return Event::fireDefault("PlayerTakeDamage", true, Player::find($playerid, true), Player::find($issuerid, true), $amount, $weaponid);
}

function OnPlayerTeamPrivmsg($playerid, $text)
{
	return Event::fireDefault("PlayerTeamPrivmsg", true, Player::find($playerid, true), $text);
}

function OnPlayerText($playerid, $text)
{
	return Event::until("PlayerText", true, Player::find($playerid, true), $text);
}

function OnPlayerUpdate($playerid)
{
	return Event::fireDefault("PlayerUpdate", true, Player::find($playerid, true));
}

function OnRconCommand($cmd)
{
	return Event::until("RconCommand", false, $cmd);
}

function OnRconLoginAttempt($ip, $playerid, $success)
{
	return Event::fireDefault("RconLoginAttempt", true, $ip, Player::find($playerid, true), $success);
}

function OnUnoccupiedVehicleUpdate($vehicleid,	$playerid,	$passengerSeat)
{
	return Event::fireDefault("UnoccupiedVehicleUpdate", true, Vehicle::find($vehicleid), Player::find($playerid, true), $passengerSeat);
}

function OnVehicleDamageStatusUpdate($vehicleid, $playerid)
{
	return Event::fireDefault("VehicleDamageStatusUpdate", true, Vehicle::find($vehicleid), Player::find($playerid, true));
}

function OnVehicleDeath($vehicleid, $killerid)
{
	return Event::fireDefault("VehicleDeath", true, Vehicle::find($vehicleid), Player::find($killerid, true));
}

function OnVehicleMod($playerid, $vehicleid, $componentid)
{
	return Event::fireDefault("VehicleMod", true, Player::find($playerid, true), Vehicle::find($vehicleid), $componentid);
}

function OnVehiclePaintjob($playerid, $vehicleid, $paintjobid)
{
	return Event::fireDefault("VehiclePaintjob", true, Player::find($playerid, true), Vehicle::find($vehicleid), $paintjobid);
}

function OnVehicleRespray($playerid, $vehicleid, $color1, $color2)
{
	return Event::fireDefault("VehicleRespray", true, Player::find($playerid, true), Vehicle::find($vehicleid), $color1, $color2);
}

function OnVehicleSpawn($vehicleid)
{
	return Event::fireDefault("OnVehicleSpawn", true, Vehicle::find($vehicleid));
}

function OnVehicleStreamIn($vehicleid, $forplayerid)
{
	return Event::fireDefault("OnVehicleStreamIn", true, Vehicle::find($vehicleid), Player::find($forplayerid, true));
}

function OnVehicleStreamOut($vehicleid, $forplayerid)
{
	return Event::fireDefault("VehicleStreamOut", true, Vehicle::find($vehicleid), Player::find($forplayerid, true));
}