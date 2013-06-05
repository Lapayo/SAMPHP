<?php
require 'playercamera.php';

class Player
{
	use ModelEvent, Storage;

	protected static $instances = array();

	public $id;

	public $camera = null;

	public static function find($id)
	{
		if($id instanceof Player)
			return $id;

		if(isset(static::$instances[$id]))
			return static::$instances[$id];

		if($id >= INVALID_PLAYER_ID)
			return null;

		return static::$instances[$id] = new static($id);
	}

	protected function __construct($id)
	{
		$this->id = $id;

		$this->camera = PlayerCamera::findForPlayer($this);
	}

	public function setSpawnInfo($team, $skin, $x, $y, $z, $rotation = 0.0, $weapon1 = 0, $weapon1_ammo = 0, $weapon2 = 0, $weapon2_ammo = 0, $weapon3 = 0, $weapon3_ammo = 0)
	{
		SetSpawnInfo($this->id, $team, $skin, $x, $y, $z, $rotation, $weapon1, $weapon1_ammo, $weapon2, $weapon2_ammo, $weapon3, $weapon3_ammo);
	}

	public function spawn()
	{
		SpawnPlayer($this->id);
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

	public function setArmedWeapon($weaponid)
	{
		return SetPlayerArmedWeapon($this->id, $weaponid);
	}

	public function getWeaponData($slot)
	{
		return (object) GetPlayerWeaponData($this->id, $slot);
	}

	public function getMoney()
	{
		return GetPlayerMoney($this->id);
	}

	public function giveMoney($amount)
	{
		return GivePlayerMoney($this->id, $amount);
	}

	public function resetMoney()
	{
		return ResetPlayerMoney($this->id);
	}

	public function setName($name)
	{
		return SetPlayerName($this->id, $name);
	}

	public function getName()
	{
		return GetPlayerName($this->id);
	}

	public function getState()
	{
		return GetPlayerState($this->id);
	}

	public function getIp()
	{
		return GetPlayerIp($this->id);
	}

	public function getPing()
	{
		return GetPlayerPing($this->id);
	}

	public function getWeapon()
	{
		return GetPlayerWeapon($this->id);
	}

	public function getKeys()
	{
		return (object) GetPlayerKeys($this->id);
	}

	public function setTime($hour, $minute)
	{
		return SetPlayerTime($this->id, $hour, $minute);
	}

	public function getTime()
	{
		return GetPlayerTime($this->id);
	}

	public function toggleClock($toggle)
	{
		return TogglePlayerClock($this->id, $toggle);
	}

	public function setWeather($weather)
	{
		return SetPlayerWeather($this->id, $weather);
	}

	public function forceClassSelection()
	{
		return ForceClassSelection($this->id);
	}

	public function setWantedLevel($level)
	{
		return SetPlayerWantedLevel($this->id, $level);
	}

	public function getWantedLevel()
	{
		return GetPlayerWantedLevel($this->id);
	}

	public function increaseWantedLevel()
	{
		$level = $this->getWantedLevel() + 1;
		$this->setWantedLevel($level);

		return $level;
	}

	public function setFightingStyle($style)
	{
		return SetPlayerFightingStyle($this->id, $style);
	}

	public function getFightingStyle()
	{
		return GetPlayerFightingStyle($this->id);
	}

	public function setVelocity($x, $y, $z)
	{
		return SetPlayerVelocity($this->id, $x, $y, $z);
	}

	public function getVelocity()
	{
		return (object) GetPlayerVelocity($this->id);
	}

	public function playCrimeReportForPlayer($forPlayer, $crime)
	{
		return PlayCrimeReportForPlayer($this->id, Player::find($forPlayer)->id, $crime);
	}

	public function playAudioStream($url, $x = 0.0, $y = 0.0, $z = 0.0, $distance = 50.0, $usePos = false)
	{
		return PlayAudioStreamForPlayer($this->id, $x, $y, $z, $distance, $usePos);
	}

	public function stopAudioStream()
	{
		return StopAudioStreamForPlayer($this->id);
	}

	public function setShopName($name)
	{
		return StopAudioStreamForPlayer($this->id, $name);
	}

	public function setSkillLevel($skill, $level)
	{
		return SetPlayerSkillLevel($this->id, $skill, $level);
	}

	public function getSurfingVehicle()
	{
		return Vehicle::find($this->getSurfingVehicleId());
	}

	public function getSurfingVehicleId()
	{
		return GetPlayerSurfingVehicleID($this->id);
	}

	public function getSurfingObjectId()
	{
		return GetPlayerSurfingObjectID($this->id);
	}

	public function removeBuilding($modelid, $x = null, $y = null, $z = null, $radius = 50.0)
	{
		if(!isset($x))	// $x unset, get player position and use this
		{
			$playerPos = $this->getPos();
			$x = $playerPos->x;
			$y = $playerPos->y;
			$z = $playerPos->z;
		}

		return RemoveBuildingForPlayer($this->id, $modelid, $x, $y, $z, $radius);
	}

	public function setAttachedObject($index, $modelid, $bone, $fOffsetX = 0.0, $fOffsetY = 0.0, $fOffsetZ = 0.0, 
		$fRotX = 0.0, $fRotY = 0.0, $fRotZ = 0.0, $fScaleX = 1.0, $fScaleY = 1.0, $fScaleZ = 1.0, $materialcolor1 = 0, $materialcolor2 = 0)
	{
		return SetPlayerAttachedObject($this->id, $index, $modelid, $bone, $fOffsetX, $fOffsetY, $fOffsetZ, $fRotX, $fRotY, $fRotZ, $fScaleX, $fScaleY, $fScaleZ, $materialcolor1, $materialcolor2);
	}
	
	public function removeAttachedObject($index)
	{
		return RemovePlayerAttachedObject($this->id, $index);
	}
	
	public function isAttachedObjectSlotUsed($index)
	{
		return IsPlayerAttachedObjectSlotUsed($this->id, $index);
	}
	
	public function editAttachedObject($index)
	{
		return EditAttachedObject($this->id, $index);
	}

	public function setChatBubble($text, $color, $drawDistance = 50.0, $expireTime = 10.0)
	{
		return SetPlayerChatBubble($this->id, $text, $color, $drawDistance, $expireTime);
	}

	public function putInVehicle($vehicle, $seat = 0)
	{
		return PutPlayerInVehicle($this->id, Vehicle::find($vehicle)->id, $seat);
	}

	public function removeFromVehicle()
	{
		return RemovePlayerFromVehicle($this->id);
	}

	public function getVehicleId()
	{
		return GetPlayerVehicleID($this->id);
	}

	public function getVehicle()
	{
		return Vehicle::find($this->getVehicleId());
	}

	public function getVehicleSeat()
	{
		return GetPlayerVehicleSeat($this->id);
	}

	public function toggleControllable($controllable)
	{
		return TogglePlayerControllable($this->id, $controllable);
	}

	public function freeze($controllable)
	{
		return $this->toggleControllable(false);
	}

	public function unfreeze($controllable)
	{
		return $this->toggleControllable(true);
	}

	public function playSound($sound, $x = 0.0, $y = 0.0, $z = 0.0)
	{
		return PlayerPlaySound($this->id, $sound, $x , $y, $z);
	}

	public function applyAnimation($lib, $name, $fD, $loop, $lockX, $lockY, $freeze, $time, $forceSync = false)
	{
		return ApplyAnimation($this->id, $lib, $name, $fD, $loop, $lockX, $lockY, $freeze, $time, $forceSync);
	}

	public function clearAnimations($forceSync = false)
	{
		return ClearAnimations($this->id, $forceSync);
	}

	public function getAnimationIndex()
	{
		return GetPlayerAnimationIndex($this->id);
	}

	public function getAnimationName()
	{
		return (object) GetAnimationName($this->id);
	}

	public function setSpecialAction($action)
	{
		return SetPlayerSpecialAction($this->id, $action);
	}

	public function getSpecialAction()
	{
		return GetPlayerSpecialAction($this->id);
	}

	public function setCheckpoint($x, $y, $z, $size = 10.0, $onEnter = null, $onLeave = null)
	{
		return Checkpoint::createForPlayer($this, $x, $y, $z, $size, $onEnter, $onLeave);
	}

	public function disableCheckpoint()
	{
		return Checkpoint::destroyForPlayer($this);
	}

	public function setRaceCheckpoint($type, $x, $y, $z, $nextx, $nexty, $nextz, $size = 10.0, $onEnter = null, $onLeave = null)
	{
		return RaceCheckpoint::createForPlayer($this, $x, $y, $z, $size, $onEnter, $onLeave);
	}

	public function disableRaceCheckpoint()
	{
		return RaceCheckpoint::destroyForPlayer($this);
	}

	public function setWorldBounds($max_x, $max_y, $max_z, $min_x, $min_y, $min_z)
	{
		return SetPlayerWorldBounds($this->id, $max_x, $max_y, $max_z, $min_x, $min_y, $min_z);
	}

	public function setMarkerForPlayer($showPlayer, $color)
	{
		return SetPlayerMarkerForPlayer($this->id, Player::find($showPlayer)->id, $color);
	}

	public function showNameTagForPlayer($showPlayer, $show = true)
	{
		return ShowPlayerNameTagForPlayer($this->id, Player::find($showPlayer)->id, $show);
	}

	public function setMapIcon($iconid, $x, $y, $z, $type, $color, $style = MAPICON_LOCAL)
	{
		return SetPlayerMapIcon($this->id, $iconid, $x, $y, $z, $type, $color, $style);
	}

	public function removeMapIcon($iconid)
	{
		return RemovePlayerMapIcon($this->id, $iconid);
	}

	public function allowTeleport($allow = true)
	{
		return AllowPlayerTeleport($this->id, $allow);
	}

	public function isAdmin()
	{
		return IsPlayerAdmin($this->id);
	}

	public function kick()
	{
		return Kick($this->id);
	}

	public function ban($reason = null)
	{
		if(isset($reason))
		{
			return BanEx($this->id, $reason);
		}

		return Ban($this->id);
	}

	public function getVersion()
	{
		return GetPlayerVersion($this->id);
	}

	public function getNetworkStats()
	{
		return GetPlayerNetworkStats($this->id);
	}

	public function sendClientMessage($color, $message)
	{
		return SendClientMessage($this->id, $color, $message);
	}

	public function sendMessageToPlayer($receiver, $message)
	{
		return SendPlayerMessageToPlayer($receiver->id, $this->id, $color, $message);
	}

	public function sendMessageFromPlayer($sender, $message)
	{
		return SendPlayerMessageToPlayer($this->id, $sender->id, $color, $message);
	}

	public function sendDiedMessage($killer, $weapon)
	{
		return SendDeathMessage($killer->id, $this->id, $weapon);
	}

	public function sendKilledMessage($killee, $weapon)
	{
		return SendDeathMessage($this->id, $killee->id, $weapon);
	}

	public function gameText($message, $time, $style)
	{
		return GameTextForPlayer($this->id, $message, $time, $style);
	}

	public function isConnected()
	{
		return IsPlayerConnected($this->id);
	}

	public function isInVehicle($vehicle = null)
	{
		if(!isset($vehicle)) return $this->isInAnyVehicle();

		return IsPlayerInVehicle($this->id, $vehicle->id);
	}

	public function isInAnyVehicle()
	{
		return IsPlayerInAnyVehicle($this->id);
	}

	public function isInCheckpoint()
	{
		return IsPlayerInCheckpoint($this->id);
	}

	public function isInRaceCheckpoint()
	{
		return IsPlayerInRaceCheckpoint($this->id);
	}

	public function isNPC()
	{
		return IsPlayerNPC($this->id);
	}

	public function setVirtualWorld($world)
	{
		return SetPlayerVirtualWorld($this->id, $world);
	}

	public function getVirtualWorld()
	{
		return GetPlayerVirtualWorld($this->id);
	}

	public function toggleSpectating($toggle)
	{
		return TogglePlayerSpectating($this->id, $toggle);
	}

	public function spectatePlayer($targetPlayer, $mode = SPECTATE_MODE_NORMAL)
	{
		return PlayerSpectatePlayer($this->id, $targetPlayer->id, $mode);
	}

	public function spectateVehicle($targetVehicle, $mode = SPECTATE_MODE_NORMAL)
	{
		return PlayerSpectatePlayer($this->id, $targetVehicle->id, $mode);
	}

	public function startRecording($type, $name)
	{
		return StopRecordingPlayerData($this->id, $type, $name);
	}

	public function stopRecording($type, $name)
	{
		return StopRecordingPlayerData($this->id);
	}

	public function selectTextDraw($hoverColor)
	{
		return SelectTextDraw($this->id, $hoverColor);
	}

	public function cancelSelectTextDraw()
	{
		return CancelSelectTextDraw($this->id);
	}

	public function enableStuntBonus($enable = true)
	{
		return EnableStuntBonusForPlayer($this->id, $enable);
	}

	public static function handleDisconnect($player)
	{
		unset(static::$instances[$player->id]);
	}
	
}

Event::after('PlayerDisconnect', array('Player', 'handleDisconnect'));

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