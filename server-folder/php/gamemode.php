<?php
require 'core/bootstrap.php';

require 'grandlarc/gamemode.php';

Command::Register('/memory', function($player) {
	$player->sendClientMessage(0xFFFFFFFF, "Memory Usage PHP: ".(memory_get_usage(false) / 1024)."KB (".(memory_get_usage(true) / 1024)."KB)");
});

Command::register('/garbage', function($player) {
	$player->sendClientMessage(0xFFFFFFFF, "Collected ".gc_collect_cycles()." cycles");
});

CMD::register('/rr', function($player) {
	GameModeExit();
});
