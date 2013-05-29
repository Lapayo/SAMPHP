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

CommandText::register('/rr', function($player, $params) {
	GameModeExit();
});

CommandText::register(array('/vehicle', '/v', '/veh'), function($player, $params) {
	$pos = $player->getPos();
	$facing = $player->getFacingAngle();

	$vehicle = Vehicle::create($params, $pos->x, $pos->y, $pos->z, $facing);

	$player->putInVehicle($vehicle);
});
