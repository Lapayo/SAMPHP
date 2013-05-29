<?php
require 'core/bootstrap.php';

Event::on('GameModeInit', function() {
	echo "I got loaded!";
});

Event::on('PlayerConnect', function($player) {
	$player->sendClientMessage(0xFFFFFF, "Garbage Collection is ".gc_enabled());
	$player->on('Spawn', function($player) {
		$player->sendClientMessage(0xFFFFFF, "Player {$player->getName()} connected.");
	});
});

Event::on("PlayerCommandText", function($player, $cmd) {
	if($cmd == "/rr")
	{
		GameModeExit();
		return true;
	}
});