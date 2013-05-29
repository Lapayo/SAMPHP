<?php

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
	return Event::fire(Player::find($playerid, true),	$playerobject,	$objectid,	$response,	$fX,	$fY,	$fZ,	$fRotX,	$fRotY,	$fRotZ);
}

function OnPlayerEnterCheckpoint($playerid)
{
	return Event::fire("PlayerEnterCheckpoint", Player::find($playerid, true));
}

function OnPlayerEnterRaceCheckpoint($playerid)
{
	return Event::fire("PlayerEnterCheckpoint", Player::find($playerid, true));
}

function OnPlayerEnterVehicle($playerid, $vehicleid, $passenger)
{
	return Event::fire("PlayerEnterVehicle", Player::find($playerid, true), $vehicleid, $passenger);
}

function OnPlayerExitVehicle($playerid, $vehicleid)
{
	return Event::fire("PlayerExitVehicle", Player::find($playerid, true), $vehicleid);
}

function OnPlayerExitedMenu($playerid)
{
	return Event::fire("PlayerExitedMenu", Player::find($playerid, true));
}

function OnPlayerGiveDamage($playerid, $damagedid, $amount, $weaponid)
{
	return Event::fire("PlayerGiveDamage", Player::find($playerid, true), $damagedid, $amount, $weaponid);
}

function OnPlayerInteriorChange($playerid, $newinteriorid, $oldinteriorid)
{
	return Event::fire("PlayerInteriorChange", Player::find($playerid, true), $newinteriorid, $oldinteriorid);
}

function OnPlayerKeyStateChange($playerid, $newkeys, $oldkeys)
{
	return Event::fire("PlayerKeyStateChange", Player::find($playerid, true), $newkeys, $oldkeys);
}

function OnPlayerLeaveCheckpoint($playerid)
{
	return Event::fire("PlayerLeaveCheckpoint", Player::find($playerid, true));
}

function OnPlayerLeaveRaceCheckpoint($playerid)
{
	return Event::fire("PlayerLeaveRaceCheckpoint", Player::find($playerid, true));
}

function OnPlayerObjectMoved($playerid, $objectid)
{
	return Event::fire("PlayerObjectMoved", Player::find($playerid, true), $objectid);
}

function OnPlayerPickUpPickup($playerid, $pickupid)
{
	return Event::fire("PlayerPickUpPickup", Player::find($playerid, true), $pickupid);
}

function OnPlayerPrivmsg($playerid, $recieverid, $text)
{
	return Event::fire("PlayerPrivmsg", Player::find($playerid, true), Player::find($recieverid, true), $text);
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
	return Event::fire("PlayerSelectObject", Player::find($playerid, true), $type, $objectid, $modelid, $fX, $fY, $fZ);
}

function OnPlayerSelectedMenuRow($playerid, $row)
{
	return Event::fire("PlayerSelectedMenuRow", Player::find($playerid, true), $row);
}

function OnPlayerSpawn($playerid)
{
	return Event::fireDefault("PlayerSpawn", true, Player::find($playerid, true));
}

function OnPlayerStateChange($playerid, $newstate, $oldstate)
{
	return Event::fire("PlayerStateChange", Player::find($playerid, true), $newstate, $oldstate);
}

function OnPlayerStreamIn($playerid, $forplayerid)
{
	return Event::fire("PlayerStreamIn", Player::find($playerid, true), Player::find($forplayerid, true));
}

function OnPlayerStreamOut($playerid, $forplayerid)
{
	return Event::fire("PlayerStreamOut", Player::find($playerid, true), Player::find($forplayerid, true));
}

function OnPlayerTakeDamage($playerid, $issuerid, $amount, $weaponid)
{
	return Event::fire("PlayerTakeDamage", Player::find($playerid, true), Player::find($issuerid, true), $amount, $weaponid);
}

function OnPlayerTeamPrivmsg($playerid, $text)
{
	return Event::fire("PlayerTeamPrivmsg", Player::find($playerid, true), $text);
}

function OnPlayerText($playerid, $text)
{
	return Event::until("PlayerText", true, Player::find($playerid, true), $text);
}

function OnPlayerUpdate($playerid)
{
	return Event::fire("PlayerUpdate", Player::find($playerid, true));
}

function OnRconCommand($cmd)
{
	return Event::fire("RconCommand", $cmd);
}

function OnRconLoginAttempt($ip, $playerid, $success)
{
	return Event::fire("RconLoginAttempt", $ip, Player::find($playerid, true), $success);
}

function OnUnoccupiedVehicleUpdate($vehicleid,	$playerid,	$passengerSeat)
{
	return Event::fire("UnoccupiedVehicleUpdate", $vehicleid, Player::find($playerid, true), $passengerSeat);
}

function OnVehicleDamageStatusUpdate($vehicleid, $playerid)
{
	return Event::fire("VehicleDamageStatusUpdate", $vehicleid, Player::find($playerid, true));
}

function OnVehicleDeath($vehicleid, $killerid)
{
	return Event::fire("VehicleDeath", $vehicleid, Player::find($killerid, true));
}

function OnVehicleMod($playerid, $vehicleid, $componentid)
{
	return Event::fire("VehicleMod", Player::find($playerid, true), $vehicleid, $componentid);
}

function OnVehiclePaintjob($playerid, $vehicleid, $paintjobid)
{
	return Event::fire("VehiclePaintjob", Player::find($playerid, true), $vehicleid, $paintjobid);
}

function OnVehicleRespray($playerid, $vehicleid, $color1, $color2)
{
	return Event::fire("VehicleRespray", Player::find($playerid, true), $vehicleid, $color1, $color2);
}

function OnVehicleSpawn($vehicleid)
{
	return Event::fire("OnVehicleSpawn", $vehicleid);
}

function OnVehicleStreamIn($vehicleid, $forplayerid)
{
	return Event::fire("OnVehicleStreamIn", $vehicleid, Player::find($forplayerid, true));
}

function OnVehicleStreamOut($vehicleid, $forplayerid)
{
	return Event::fire("VehicleStreamOut", $vehicleid, Player::find($forplayerid, true));
}
?>