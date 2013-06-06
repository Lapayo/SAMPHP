<?php
require 'spawns.php';

define('COLOR_WHITE', '0xFFFFFFFF');
define('COLOR_NORMAL_PLAYER', '0xFF4444FF');

define('CITY_LOS_SANTOS', '0');
define('CITY_SAN_FIERRO', '1');
define('CITY_LAS_VENTURAS', '2');


// Text draws

function CreateCityTextDraw($text)
{
	return TextDraw::create(10.0, 380.0, $text)
		->useBox(false)
		->setLetterSize(1.25, 3.0)
		->setFont(0)
		->setShadow(false)
		->setOutline(true)
		->setColor(0xEEEEEEFF)
		->setBackgroundColor(0x000000FF);
}

CreateCityTextDraw("Los Santos")->name("LosSantos");
CreateCityTextDraw("San Fierro")->name("SanFierro");
CreateCityTextDraw("Las Venturas")->name("LasVenturas");

TextDraw::create(10.0, 415.0,
	   " Press ~b~~k~~GO_LEFT~ ~w~or ~b~~k~~GO_RIGHT~ ~w~to switch cities.~n~ Press ~r~~k~~PED_FIREWEAPON~ ~w~to select.")
	->name("ClassSelectHelper")
	->useBox(true)
	->setBoxColor(0x222222BB)
	->setLetterSize(0.3, 1.0)
	->setTextSize(400, 40)
	->setFont(2)
	->setShadow(false)
	->setOutline(true)
	->setBackgroundColor(0x000000FF)
	->setColor(0xFFFFFFFF);


// Class Selection
function ClassSel_SetupCharSelection($player)
{
	switch($player->citySelection)
	{
		case CITY_LOS_SANTOS:
			$player->setInterior(11);
			$player->setPos(508.7362, -87.4335, 998.9609);
			$player->setFacingAngle(0.0);
			$player->camera->setPos(508.7362, -83.4335, 998.9609);
			$player->camera->setLookAt(508.7362, -87.4335, 998.9609);
			break;
		case CITY_SAN_FIERRO:
			$player->setInterior(3);
			$player->setPos(-2673.8381, 1399.7424, 918.3516);
			$player->setFacingAngle(181.0);
			$player->camera->setPos(-2673.2776, 1394.3859, 918.3516);
			$player->camera->setPos(-2673.8381, 1399.7424, 918.3516);
			break;
		case CITY_LAS_VENTURAS:
			$player->setInterior(3);
			$player->setPos(349.0453, 193.2271, 1014.1797);
			$player->setFacingAngle(286.25);
			$player->camera->setPos(352.9164, 194.5702, 1014.1875);
			$player->camera->setPos(349.0453, 193.2271, 1014.1797);
			break;
	}
}

function ClassSel_SetupSelectedCity($player)
{
	if($player->citySelection == -1)
		$player->citySelection = CITY_LOS_SANTOS;

	$player->setInterior(0);

	TextDraw::named('LosSantos')->hideForPlayer($player);
	TextDraw::named('SanFierro')->hideForPlayer($player);
	TextDraw::named('LasVenturas')->hideForPlayer($player);

	switch($player->citySelection)
	{
		case CITY_LOS_SANTOS:
			TextDraw::named('LosSantos')->showForPlayer($player);
			$player->camera->setPos(1630.6136, -2286.0298, 110.0);
			$player->camera->setLookAt(1887.6034, -1682.1442, 47.6167);
			break;
		case CITY_SAN_FIERRO:
			TextDraw::named('SanFierro')->showForPlayer($player);
			$player->camera->setPos(-1300.8754, 68.0546, 129.4823);
			$player->camera->setLookAt(-1817.9412, 769.3878, 132.6589);
			break;
		case CITY_LAS_VENTURAS:
			TextDraw::named('LasVenturas')->showForPlayer($player);
			$player->camera->setPos(1310.6155, 1675.9182, 110.7390);
			$player->camera->setLookAt(2285.2944, 1919.3756, 68.2275);
			break;
	}
}

function ClassSel_SwitchToNextCity($player)
{
	if(++$player->citySelection > CITY_LAS_VENTURAS)
		$player->citySelection = CITY_LOS_SANTOS;

	$player->playSound(1052);

	$player->lastCitySelectionTick = GetTickCount();

	ClassSel_SetupSelectedCity($player);
}

function ClassSel_SwitchToPreviousCity($player)
{
	if(--$player->citySelection < CITY_LOS_SANTOS)
		$player->citySelection = CITY_LAS_VENTURAS;

	$player->playSound(1053);

	$player->lastCitySelectionTick = GetTickCount();

	ClassSel_SetupSelectedCity($player);
}


function ClassSel_HandleCitySelection($player)
{
    $keys = $player->getKeys();
    
    if($player->citySelection == -1)
    {
		ClassSel_SwitchToNextCity($player);
		return;
	}

	// only allow new selection every ~500 ms
	if((GetTickCount() - $player->lastCitySelectionTick) < 500) return;
	
	if($keys->keys & KEY_FIRE)
	{
		$player->hasCitySelected = true;
		$player->toggleSpectating(false);

		TextDraw::named('LosSantos')->hideForPlayer($player);
		TextDraw::named('SanFierro')->hideForPlayer($player);
		TextDraw::named('LasVenturas')->hideForPlayer($player);
		TextDraw::named('ClassSelectHelper')->hideForPlayer($player);

	    return;
	}
	
	if($keys->leftright > 0) {
	   ClassSel_SwitchToNextCity($player);
	}
	else if($keys->leftright < 0) {
	   ClassSel_SwitchToPreviousCity($player);
	}
}



Event::on('PlayerConnect', function($player) {
	$player->gameText("~w~Grand Larceny", 3000, 4);
	$player->sendClientMessage(COLOR_WHITE, "Welcome to Grand Larceny");

	$player->citySelection = -1;
	$player->hasCitySelected = false;
	$player->lastCitySelectionTick = GetTickCount();
});

Event::on('PlayerSpawn', function($player) {
	global $gSpawns;

	if($player->isNPC()) return;

	$player->setInterior(0);
	$player->toggleClock(false);
	$player->resetMoney();
	$player->giveMoney(30000);

	// if they ever return to class selection make them city
	// select again first
	$player->hasCitySelected = 0;

	$spawns = $gSpawns[$player->citySelection];

	$rand = rand(0, count($spawns) - 1);

	$spawn = $spawns[$rand];

	$player->setPos($spawn[0], $spawn[1], $spawn[2]);
	$player->setFacingAngle($spawn[3]);

	$skills = [WEAPONSKILL_PISTOL, WEAPONSKILL_PISTOL_SILENCED, WEAPONSKILL_DESERT_EAGLE, WEAPONSKILL_SHOTGUN, WEAPONSKILL_SAWNOFF_SHOTGUN,
		WEAPONSKILL_SPAS12_SHOTGUN, WEAPONSKILL_MICRO_UZI, WEAPONSKILL_MP5, WEAPONSKILL_AK47, WEAPONSKILL_M4, WEAPONSKILL_SNIPERRIFLE];

	foreach($skills as $skill)
		$player->setSkillLevel($skill, 200);

	$player->giveWeapon(WEAPON_COLT45, 100);
});

Event::on('PlayerDeath', function($player, $killer, $reason) {
	if(!$killer)
	{
		$player->resetMoney();
		return;
	}

	$cash = $player->getMoney();
	if($cash > 0)
	{
		$killer->giveMoney($cash);
		$player->resetMoney();
	}
});

Event::on('PlayerRequestClass', function($player, $classid) {
	if($player->isNPC()) return true;

	if($player->hasCitySelected)
	{
		ClassSel_SetupCharSelection($player);
		return true;
	}else{
		if($player->getState() != PLAYER_STATE_SPECTATING)
		{
			$player->toggleSpectating(true);
			TextDraw::named('ClassSelectHelper')->showForPlayer($player);
			$player->citySelection = -1;
		}
	}

	return false;
});

Event::on('GameModeInit', function() {
	Server::setGameModeText("Grand Larceny PHP");
	Server::showPlayerMarkers();
	Server::showNameTags();
	Server::setNameTagDrawDistance(40.0);
	Server::enableStuntBonus(false);
	Server::disableInteriorEnterExits();
	Server::setWeather(2);
	

	$classes = require 'classes.php';

	foreach($classes as $class)
		Server::addPlayerClass($class[0], $class[1], $class[2], $class[3], $class[4], $class[5], $class[6], $class[7], $class[8], $class[9], $class[10]);

	$spawnedVehicles = Vehicle::loadStaticVehiclesFromFile(["vehicles/trains.txt", "vehicles/pilots.txt", "vehicles/lv_law.txt",
		"vehicles/lv_airport.txt", "vehicles/lv_gen.txt", "vehicles/sf_law.txt", "vehicles/sf_airport.txt",
		"vehicles/sf_gen.txt", "vehicles/ls_law.txt", "vehicles/ls_airport.txt", "vehicles/ls_gen_inner.txt",
		"vehicles/ls_gen_outer.txt", "vehicles/whetstone.txt", "vehicles/bone.txt", "vehicles/flint.txt",
		"vehicles/tierra.txt", "vehicles/red_county.txt"]);

	echo "Total vehicles from files: {$spawnedVehicles}";
});

Event::on('PlayerUpdate', function($player) {
	if(!$player->isConnected()) return false;

	if(!$player->hasCitySelected && $player->getState() == PLAYER_STATE_SPECTATING)
	{
	    ClassSel_HandleCitySelection($player);
	    return true;
	}

	if($player->getInterior() != 0 && $player->getWeapon() != 0)
	{
	    $player->setArmedWeapon(0); // fists
	    return false; // no syncing until they change their weapon
	}

	if($player->getWeapon() == WEAPON_MINIGUN
		|| $player->getSpecialAction() == SPECIAL_ACTION_USEJETPACK)
	{
	    $player->kick();
	    return false;
	}
});