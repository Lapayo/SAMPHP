<?php
require 'core/bootstrap.php';

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
