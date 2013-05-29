<?php
require 'core/bootstrap.php';

Event::on('GameModeInit', function() {
	
});

Event::on('PlayerConnect', function($player) {
	$player->on('Spawn', function($player) {
		$player->sendClientMessage(0x0, "Player {$player->getName()} connected.");
	});
});