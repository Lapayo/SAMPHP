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
		return ShowPlayerMarkers($show);
	}

	public static function gameModeExit()
	{
		return GameModeExit();
	}

	public static function sendClientMessageToAll($color, $message)
	{
		return SendClientMessageToAll($color, $message);
	}
}