<?php
class Server
{
	public static function getVar($varname)
	{
		return GetServerVar($varname);
	}

	public static function setGameModeText($text)
	{
		return SetGameModeText($text);
	}
	
	public static function setTeamCount($count)
	{
		return SetTeamCount($count);
	}
	
	public static function addPlayerClass($modelid, $spawn_x, $spawn_y, $spawn_z, $z_angle,
		$weapon1 = 0, $weapon1_ammo = 0, $weapon2 = 0, $weapon2_ammo = 0, $weapon3 = 0, $weapon3_ammo = 0)
	{
		return AddPlayerClass($modelid, $spawn_x, $spawn_y, $spawn_z, $z_angle, $weapon1, $weapon1_ammo, $weapon2, $weapon2_ammo, $weapon3, $weapon3_ammo);
	}
	
	public static function addPlayerClassEx($teamid, $modelid, $spawn_x, $spawn_y, $spawn_z, $z_angle,
		$weapon1 = 0, $weapon1_ammo = 0, $weapon2 = 0, $weapon2_ammo = 0, $weapon3 = 0, $weapon3_ammo = 0)
	{
		return AddPlayerClassEx($teamid, $modelid, $spawn_x, $spawn_y, $spawn_z, $z_angle, $weapon1, $weapon1_ammo, $weapon2, $weapon2_ammo, $weapon3, $weapon3_ammo);
	}
	
	public static function showNameTags($show = true)
	{
		return ShowNameTags($show);
	}
	
	public static function showPlayerMarkers($mode = PLAYER_MARKERS_MODE_GLOBAL)
	{
		return ShowPlayerMarkers($mode);
	}

	public static function gameModeExit()
	{
		return GameModeExit();
	}

	public static function setWorldTime($hour)
	{
		return SetWorldTime($hour);
	}

	public static function getWeaponName($weaponid)
	{
		return GetWeaponName($weaponid);
	}

	public static function enableTirePopping($enable = true)
	{
		return EnableTirePopping($enable);
	}

	public static function enableZoneNames($enable = true)
	{
		return EnableZoneNames($enable);
	}

	public static function enableVehicleFriendlyFire()
	{
		return EnableVehicleFriendlyFire();
	}

	public static function allowInteriorWeapons($allow = true)
	{
		return AllowInteriorWeapons($allow);
	}

	public static function setWeather($weatherid)
	{
		return SetWeather($weatherid);
	}

	public static function setGravity($gravity)
	{
		return SetGravity($gravity);
	}

	public static function setDeathDropAmount($amount)
	{
		return SetDeathDropAmount($amount);
	}

	public static function allowAdminTeleport($allow = true)
	{
		return AllowAdminTeleport($allow);
	}

	public static function createExplosion($x, $y, $z, $type, $radius)
	{
		return CreateExplosion($x, $y, $z, $type, $radius);
	}

	public static function usePlayerPedAnims()
	{
		return UsePlayerPedAnims();
	}

	public static function disableInteriorEnterExits()
	{
		return DisableInteriorEnterExits();
	}

	public static function setNameTagDrawDistance($distance)
	{
		return SetNameTagDrawDistance($distance);
	}

	public static function disableNameTagLOS()
	{
		return DisableNameTagLOS();
	}

	public static function limitGlobalChatRadius($radius)
	{
		return LimitGlobalChatRadius($radius);
	}

	public static function limitPlayerMarkerRadius($radius)
	{
		return LimitPlayerMarkerRadius($radius);
	}

	public static function enableStuntBonus($enable = true)
	{
		return EnableStuntBonusForAll($enable);
	}

	public static function connectNPC($name, $script)
	{
		return ConnectNPC($name, $script);
	}

	public static function sendRconCommand($command)
	{
		return SendRconCommand($command);
	}

	public static function getNetworkStats()
	{
		return GetNetworkStats();
	}

	public static function getMaxPlayers()
	{
		return GetMaxPlayers();
	}

	public static function getTickCount()
	{
		return GetTickCount();
	}

	public static function sendClientMessageToAll($color, $message)
	{
		return SendClientMessageToAll($color, $message);
	}

	public static function gameTextForAll($message, $time, $style)
	{
		return GameTextForAll($message, $time, $style);
	}

	public static function gameTextForPlayer($player, $message, $time, $style)
	{
		return GameTextForPlayer($player->id, $message, $time, $style);
	}

	public static function blockIpAddress($ipaddress, $timems) {
		return BlockIpAddress($ipaddress, $timems);
	}

	public static function unBlockIpAddress($ipaddress) {
		return UnBlockIpAddress($ipaddress);
	}
}
