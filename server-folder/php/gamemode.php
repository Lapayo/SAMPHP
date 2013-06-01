<?php
require 'core/bootstrap.php';

$spawnVehicleMenu = Menu::create("Spawn Vehicle", 200, 100, 150, 50)
	->addRow("Stallion", 439, "$500")
	->addRow("Pizzaboy", 448, "$500", 500)
	->addRow("Turismo", 451, "$50000")
	->addRow("Flatbed", 455, "$50", 500)
	->addRow("Yankee", 456, "$456", 456)
	->on('PlayerSelectedRow', function($player, $id, $price) {
		Server::sendClientMessageToAll(0xFFFFFF, $player->getName()." bought vehicle with id $id for \$$price!");

		$pos = $player->getPos();
		$facing = $player->getFacingAngle();

		$vehicle = Vehicle::create($id, $pos->x, $pos->y, $pos->z, $facing);

		$player->putInVehicle($vehicle);
	});

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

CommandText::register('/buy', function($player, $params) use($spawnVehicleMenu) {
	$spawnVehicleMenu->showForPlayer($player);
});
