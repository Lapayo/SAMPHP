<?php
require 'core/bootstrap.php';

//RegisterAMXNative(['GetWeaponName', 'WeaponName'], "null", "long", "ref_string_fixed:100");
RegisterAMXNative(['GetWeaponName', 'WeaponName'], "null", "long", "ref_string");
RegisterAMXNative(['GetPlayerPos', 'PlayerPos'], "null", "int", "ref_float", "ref_float", "ref_float");
RegisterAMXNative(['SendClientMessage', 'SendMsg'], "null", "int", "int", "string");
RegisterAMXNative(['DisableInteriorEnterExits', 'DIEE']);

var_dump(AMXNativeExists("notExisting"));
var_dump(AMXNativeExists("SendClientMessage"));
DIEE();


require 'grandlarc/gamemode.php';

CommandText::register('/memory', function($player) {
	$player->sendClientMessage(0xFFFFFFFF, "Memory Usage PHP: ".(memory_get_usage(false) / 1024)."KB (".(memory_get_usage(true) / 1024)."KB)");
});

CommandText::register('/garbage', function($player) {
	$player->sendClientMessage(0xFFFFFFFF, "Collected ".gc_collect_cycles()." cycles");
});

CommandText::register('/rr', function($player) {
	GameModeExit();
});

CommandText::register('/testing', function($player) {
	$x = 0.0;
	$y = 0.0;
	$z = 0;
	PlayerPos($player->id, $x, $y, $z);

	SendMsg($player->id, 0xFFFFFFFF, "x: ".$x." y: ".$y." z: ".$z);
});