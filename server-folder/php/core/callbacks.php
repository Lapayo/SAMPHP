<?php

function OnDialogResponse($playerid, $dialogid, $response, $listitem, $inputtext)
{
	return Event::fire("DialogResponse", $playerid, $dialogid, $response, $listitem, $inputtext);
}

function OnEnterExitModShop($playerid, $enterexit, $interiorid)
{
	return Event::fire("EnterExitModShop", $playerid, $enterexit, $interiorid);
}

function OnGameModeExit()
{
	return Event::fire("GameModeExit");
}

function OnGameModeInit() 
{
	return Event::fire("GameModeInit");
}

function OnObjectMoved($objectid)
{
	return Event::fire("ObjectMoved");
}

function OnPlayerClickMap($playerid, $fx, $fy, $fz)
{
	return Event::fire("PlayerClickMap", $playerid, $fx, $fy, $fz);
}

function OnPlayerClickPlayer($playerid, $clickedplayerid, $source)
{
	return Event::fire("PlayerClickPlayer", $playerid, $clickedplayerid, $source);
}

function OnPlayerClickPlayerTextDraw($playerid, $playertextid)
{
	return Event::fire("PlayerClickPlayerTextDraw", $playerid, $playertextid);
}

function OnPlayerClickTextDraw($playerid, $clickedid)
{
	return Event::fire("PlayerClickTextDraw", $playerid, $clickedid);
}

function OnPlayerCommandText($playerid, $cmdtext)
{
	return Event::fire("PlayerCommandText", $playerid, $cmdtext);
}

function OnPlayerConnect($playerid)
{
	return Event::fire("PlayerConnect", $playerid);
}

function OnPlayerDeath($playerid, $killerid, $reason)
{
	return Event::fire("PlayerDeath", $playerid, $killerid, $reason);
}

function OnPlayerDisconnect($playerid, $reason)
{
	return Event::fire("PlayerDisconnect", $playerid, $reason);
}

function OnPlayerEditAttachedObject($playerid, $response, $index, $modelid, $boneid, $fOffsetX, $fOffsetY, $fOffsetZ, $fRotX, $fRotY, $fRotZ, $fScaleX, $fScaleY, $fScaleZ)
{
	return Event::fire("PlayerEditAttachedObject", $playerid, $response, $index, $modelid, $boneid, $fOffsetX, $fOffsetY, $fOffsetZ, $fRotX, $fRotY, $fRotZ, $fScaleX, $fScaleY, $fScaleZ);
}

function OnPlayerEditObject($playerid,	$playerobject,	$objectid,	$response,	$fX,	$fY,	$fZ,	$fRotX,	$fRotY,	$fRotZ)
{
	return Event::fire($playerid,	$playerobject,	$objectid,	$response,	$fX,	$fY,	$fZ,	$fRotX,	$fRotY,	$fRotZ);
}

function OnPlayerEnterCheckpoint($playerid)
{
	return Event::fire("PlayerEnterCheckpoint", $playerid);
}

function OnPlayerEnterRaceCheckpoint($playerid)
{
	return Event::fire("PlayerEnterCheckpoint", $playerid);
}

function OnPlayerEnterVehicle($playerid, $vehicleid, $passenger)
{
	return Event::fire("PlayerEnterVehicle", $playerid, $vehicleid, $passenger);
}

function OnPlayerExitVehicle($playerid, $vehicleid)
{
	return Event::fire("PlayerExitVehicle", $playerid, $vehicleid);
}

function OnPlayerExitedMenu($playerid)
{
	return Event::fire("PlayerExitedMenu", $playerid);
}

function OnPlayerGiveDamage($playerid, $damagedid, $amount, $weaponid)
{
	return Event::fire("PlayerGiveDamage", $playerid, $damagedid, $amount, $weaponid);
}

function OnPlayerInteriorChange($playerid, $newinteriorid, $oldinteriorid)
{
	return Event::fire("PlayerInteriorChange", $playerid, $newinteriorid, $oldinteriorid);
}

function OnPlayerKeyStateChange($playerid, $newkeys, $oldkeys)
{
	return Event::fire("PlayerKeyStateChange", $playerid, $newkeys, $oldkeys);
}

function OnPlayerLeaveCheckpoint($playerid)
{
	return Event::fire("PlayerLeaveCheckpoint", $playerid);
}

function OnPlayerLeaveRaceCheckpoint($playerid)
{
	return Event::fire("PlayerLeaveRaceCheckpoint", $playerid);
}

function OnPlayerObjectMoved($playerid, $objectid)
{
	return Event::fire("PlayerObjectMoved", $playerid, $objectid);
}

function OnPlayerPickUpPickup($playerid, $pickupid)
{
	return Event::fire("PlayerPickUpPickup", $playerid, $pickupid);
}

function OnPlayerPrivmsg($playerid, $recieverid, $text)
{
	return Event::fire("PlayerPrivmsg", $playerid, $recieverid, $text);
}

function OnPlayerRequestClass($playerid, $classid)
{
	return Event::fire("PlayerRequestClass", $playerid, $classid);
}

function OnPlayerRequestSpawn($playerid)
{
	return Event::fire("PlayerRequestSpawn", $playerid);
}

function OnPlayerSelectObject($playerid, $type, $objectid, $modelid, $fX, $fY, $fZ)
{
	return Event::fire("PlayerSelectObject", $playerid, $type, $objectid, $modelid, $fX, $fY, $fZ);
}

function OnPlayerSelectedMenuRow($playerid, $row)
{
	return Event::fire("PlayerSelectedMenuRow", $playerid, $row);
}

function OnPlayerSpawn($playerid)
{
	return Event::fire("PlayerSpawn", $playerid);
}

function OnPlayerStateChange($playerid, $newstate, $oldstate)
{
	return Event::fire("PlayerStateChange", $playerid, $newstate, $oldstate);
}

function OnPlayerStreamIn($playerid, $forplayerid)
{
	return Event::fire("PlayerStreamIn", $playerid, $forplayerid);
}

function OnPlayerStreamOut($playerid, $forplayerid)
{
	return Event::fire("PlayerStreamOut", $playerid, $forplayerid);
}

function OnPlayerTakeDamage($playerid, $issuerid, $amount, $weaponid)
{
	return Event::fire("PlayerTakeDamage", $playerid, $issuerid, $amount, $weaponid);
}

function OnPlayerTeamPrivmsg($playerid, $text)
{
	return Event::fire("PlayerTeamPrivmsg", $playerid, $text);
}

function OnPlayerText($playerid, $text)
{
	return Event::fire("PlayerText", $playerid, $text);
}

function OnPlayerUpdate($playerid)
{
	return Event::fire("PlayerUpdate", $playerid);
}

function OnRconCommand($cmd)
{
	return Event::fire("RconCommand", $cmd);
}

function OnRconLoginAttempt($ip, $playerid, $success)
{
	return Event::fire("RconLoginAttempt", $ip, $playerid, $success);
}

function OnUnoccupiedVehicleUpdate($vehicleid,	$playerid,	$passengerSeat)
{
	return Event::fire("UnoccupiedVehicleUpdate", $vehicleid, $playerid, $passengerSeat);
}

function OnVehicleDamageStatusUpdate($vehicleid, $playerid)
{
	return Event::fire("VehicleDamageStatusUpdate", $vehicleid, $playerid);
}

function OnVehicleDeath($vehicleid, $killerid)
{
	return Event::fire("VehicleDeath", $vehicleid, $killerid);
}

function OnVehicleMod($playerid, $vehicleid, $componentid)
{
	return Event::fire("VehicleMod", $playerid, $vehicleid, $componentid);
}

function OnVehiclePaintjob($playerid, $vehicleid, $paintjobid)
{
	return Event::fire("VehiclePaintjob", $playerid, $vehicleid, $paintjobid);
}

function OnVehicleRespray($playerid, $vehicleid, $color1, $color2)
{
	return Event::fire("VehicleRespray", $playerid, $vehicleid, $color1, $color2);
}

function OnVehicleSpawn($vehicleid)
{
	return Event::fire("OnVehicleSpawn", $vehicleid);
}

function OnVehicleStreamIn($vehicleid, $forplayerid)
{
	return Event::fire("OnVehicleStreamIn", $vehicleid, $forplayerid);
}

function OnVehicleStreamOut($vehicleid, $forplayerid)
{
	return Event::fire("VehicleStreamOut", $vehicleid, $forplayerid);
}
?>