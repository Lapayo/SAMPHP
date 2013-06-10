<?php
/*
$var = "hi";
define("TEST", 0x1234);
$arg1 = 1;
CallAMXNative($var, "id", $arg1);
var_dump($arg1);

exit;
*/

require 'core/bootstrap.php';
RegisterAMXNative(["GetPlayerName", "PlayerName"], null, "integer", "ref_string_len:25");
PlayerName(0, $name);

require 'grandlarc/gamemode.php';

CommandText::register('/memory', function($player) {
	$player->sendClientMessage(0xFFFFFFFF, "Memory Usage PHP: ".(memory_get_usage(false) / 1024)."KB (".(memory_get_usage(true) / 1024)."KB)");
});

CommandText::register('/garbage', function($player) {
	$player->sendClientMessage(0xFFFFFFFF, "Collected ".gc_collect_cycles()." cycles");
});
