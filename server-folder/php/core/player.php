<?php

class Player
{
	use ModelEvent;

	protected static $instances = array();

	public $id;

	public static function find($id, $disableChecks = false)
	{
		if($id instanceof Player)
			return $id;

		if(isset(static::$instances[$id]))
			return static::$instances[$id];

		if(!$disableChecks && !IsPlayerConnected($id))
			return null;

		return static::$instances[$id] = new static($id);
	}

	protected function __construct($id)
	{
		$this->id = $id;
	}

	public function setPos($x, $y, $z)
	{
		return SetPlayerPos($this->id, $x, $y, $z);
	}

	public function setPosFindZ($x, $y, $z)
	{
		return SetPlayerPosFindZ($this->id, $x, $y, $z);
	}

	public function getPos()
	{
		return (object) GetPlayerPos($this->id);
	}

	public function setFacingAngle($angle)
	{
		return SetPlayerFacingAngle($this->id, $angle);
	}

	public function getFacingAngle()
	{
		return GetPlayerFacingAngle($this->id);
	}

	public function isInRangeOfPoint($range, $x, $y, $z)
	{
		return IsPlayerInRangeOfPoint($this->id, $range, $x, $y, $z);
	}

	public function getDistanceFromPoint($x, $y, $z)
	{
		return GetPlayerDistanceFromPoint($this->id, $x, $y, $z);
	}

	public function isPlayerStreamedIn($forPlayer)
	{
		return IsPlayerStreamedIn($this->id, Player::find($forPlayer)->id);
	}

	public function setInterior($interior)
	{
		return SetPlayerInterior($this->id, $interior);
	}

	public function getInterior()
	{
		return GetPlayerInterior($this->id);
	}

	public function setHealth($health)
	{
		return SetPlayerHealth($this->id, $health);
	}

	public function getHealth()
	{
		return GetPlayerHealth($this->id);
	}

	public function setArmour($armour)
	{
		return SetPlayerArmour($this->id, $armour);
	}

	public function getArmour()
	{
		return GetPlayerArmour($this->id);
	}

	public function setAmmo($weaponslot, $ammo)
	{
		return SetPlayerAmmo($this->id, $weaponslot, $ammo);
	}

	public function getAmmo()
	{
		return GetPlayerAmmo($this->id);
	}

	public function getWeaponState()
	{
		return GetPlayerWeaponState($this->id);
	}

	public function getTargetPlayer()
	{
		return GetPlayerTargetPlayer($this->id);
	}

	public function setTeam($team)
	{
		return SetPlayerTeam($this->id, $team);
	}

	public function getTeam()
	{
		return GetPlayerTeam($this->id);
	}

	public function setScore($score)
	{
		return SetPlayerScore($this->id, $score);
	}

	public function getScore()
	{
		return GetPlayerScore($this->id);
	}

	public function setDrunkLevel($drunkLevel)
	{
		return SetPlayerDrunkLevel($this->id, $drunkLevel);
	}

	public function getDrunkLevel()
	{
		return GetPlayerDrunkLevel($this->id);
	}

	public function setColor($color)
	{
		return SetPlayerColor($this->id, $color);
	}

	public function getColor()
	{
		return GetPlayerColor($this->id);
	}

	public function setSkin($skin)
	{
		return SetPlayerSkin($this->id, $skin);
	}

	public function getSkin()
	{
		return GetPlayerSkin($this->id);
	}

	public function giveWeapon($weaponid, $ammo)
	{
		return GivePlayerWeapon($this->id, $weaponid, $ammo);
	}

	public function resetWeapons()
	{
		return ResetPlayerWeapons($this->id);
	}


	/*
// Player info
x native SetPlayerArmedWeapon(playerid, weaponid);
x native GetPlayerWeaponData(playerid, slot, &weapons, &ammo);
x native GetPlayerMoney(playerid);
x native GivePlayerMoney(playerid,money);
x native ResetPlayerMoney(playerid);
x native SetPlayerName(playerid, const name[]);
x native GetPlayerState(playerid);
x native GetPlayerIp(playerid, name[], len);
x native GetPlayerPing(playerid);
x native GetPlayerWeapon(playerid);
x native GetPlayerKeys(playerid, &keys, &updown, &leftright);
x native GetPlayerName(playerid, const name[], len);
x native SetPlayerTime(playerid, hour, minute);
x native GetPlayerTime(playerid, &hour, &minute);
x native TogglePlayerClock(playerid, toggle);
x native SetPlayerWeather(playerid, weather);
x native ForceClassSelection(playerid);
x native SetPlayerWantedLevel(playerid, level);
x native GetPlayerWantedLevel(playerid);
x native SetPlayerFightingStyle(playerid, style);
x native GetPlayerFightingStyle(playerid);
x native SetPlayerVelocity(playerid, Float:X, Float:Y, Float:Z);
x native GetPlayerVelocity( playerid, &Float:X, &Float:Y, &Float:Z );
x native PlayCrimeReportForPlayer(playerid, suspectid, crime);
x native PlayAudioStreamForPlayer(playerid, url[], Float:posX = 0.0, Float:posY = 0.0, Float:posZ = 0.0, Float:distance = 50.0, usepos = 0);
x native StopAudioStreamForPlayer(playerid);
x native SetPlayerShopName(playerid, shopname[]);
x native SetPlayerSkillLevel(playerid, skill, level);
x native GetPlayerSurfingVehicleID(playerid);
x native GetPlayerSurfingObjectID(playerid);
x native RemoveBuildingForPlayer(playerid, modelid, Float:fX, Float:fY, Float:fZ, Float:fRadius);

x native SetPlayerAttachedObject(playerid, index, modelid, bone, Float:fOffsetX = 0.0, Float:fOffsetY = 0.0, Float:fOffsetZ = 0.0, Float:fRotX = 0.0, Float:fRotY = 0.0, Float:fRotZ = 0.0, Float:fScaleX = 1.0, Float:fScaleY = 1.0, Float:fScaleZ = 1.0, materialcolor1 = 0, materialcolor2 = 0);
x native RemovePlayerAttachedObject(playerid, index);
x native IsPlayerAttachedObjectSlotUsed(playerid, index);
x native EditAttachedObject(playerid, index);

	*/

	public function putInVehicle($vehicle, $seat = 0)
	{
		return PutPlayerInVehicle($this->id, Vehicle::find($vehicle)->id, $seat);
	}

	public function kick()
	{
		return Kick($this->id);
	}

	public function sendClientMessage($color, $message)
	{
		return SendClientMessage($this->id, $color, $message);
	}

	public function getName()
	{
		return GetPlayerName($this->id);
	}

	
}


$callbackNames = array();

foreach($callbackList as $callback)
{
	$prefix = "OnPlayer";
	$prefix_len = strlen($prefix);

	if(substr($callback, 0, $prefix_len) == $prefix)
	{
		$callbackNames[$callback] = substr($callback, $prefix_len);
	}
}

foreach($callbackNames as $extern => $intern)
{
	Event::on($extern, function($player) use($intern) {
		$args = func_get_args();
		array_unshift($args, $intern);
				
		call_user_func_array(array($player, 'fire'), $args);
	});
}


/*
Usage:
Player::find(123)->on('Spawn', function($player) {
	$player->kick();
});
*/