<?php
require 'core/bootstrap.php';

try {
	$db = new PDO('sqlite:memory');
	//$db = new PDO('mysql:host=127.0.0.1;dbname=test', 'root', '');
	foreach ($db->query('SELECT * from FOO') as $row)
	{
		print_r($row);
	}
}catch (PDOException $e)
{
	echo "Error!: ".$e->getMessage();
}




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

$testDialog = Dialog::create(DIALOG_STYLE_LIST, 'title', 'okay', 'cancel')
	->addListItem('Infernus', 411)
	->addListItem('FBI Truck', 528)
	->addListItem('Bike', 509)
	->addListItem('BMX', 481)
	->addListItem('Mountain Bike', 510)
	->addListItem('Firetruck', 407)
	->addListItem('Firetruck with Ladder', 544)
	->addListItem('SWAT', 601)
	->addListItem('Tank (Rhino)', 432)
	->on('Response', function($player, $dialog, $button, $value){
		if($button)
		{
			$pos = $player->getPos();
			$facing = $player->getFacingAngle();
	
			$vehicle = Vehicle::create($value, $pos->x, $pos->y, $pos->z, $facing);
	
			$player->putInVehicle($vehicle);						
		}
	});

Dialog::createList("Spawn Vehicle", "Okay", "Oh no")
	->addRow("Stallion", 439)
	->addRow("Pizzaboy", 448)
	->addRow("Turismo", 451)
	->addRow("Flatbed", 455)
	->addRow("Yankee", 456)
	->on("Success", function($player, $dialog, $id) {
		$pos = $player->getPos();
		$facing = $player->getFacingAngle();

		$vehicle = Vehicle::create($id, $pos->x, $pos->y, $pos->z, $facing);

		$player->putInVehicle($vehicle);
	})
	->name('spawnvehicle');

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

CommandText::register('/goto', function($player, $params) {
	$destPlayer = Player::find($params);

	$interior = $destPlayer->getInterior();
	$pos = $destPlayer->getPos();

	$player->setInterior($interior);
	$player->setPos($pos->x, $pos->y, $pos->z);
});

CommandText::register('/dialog', function($player, $params) use($testDialog){
	$testDialog->showPlayer($player);
});

CommandText::register('/dialog2', function($player, $params) {
	Dialog::named('spawnvehicle')->showPlayer($player);
});


$objects = array(); 
Event::on('PlayerEnterVehicle', function($player, $vehicle) use($objects) {
	$objects[$player->id] = CreatePlayerObject($player->id, 19300, 0.0000, -1282.9984, 10.1493, 0.0000, -1, -1, 100);
	AttachPlayerObjectToVehicle($player->id, $objects[$player->id], $vehicle->id, -0.6, -0.3, 0.490000, 0.000000, 0.000000, 0.000000);
	AttachCameraToPlayerObject($player->id, $objects[$player->id]);
});

Event::on('PlayerExitVehicle', function($player, $vehicle) use($objects) {
	SetCameraBehindPlayer($player->id);
	DestroyPlayerObject($player->id, $objects[$player->id]);
});
