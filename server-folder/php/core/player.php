<?php

class Player
{
	use ModelEvent;
	protected $eventPrefix = "Player";

	protected static $instances = array();

	protected $id;

	public static function find($id, $disableChecks = false)
	{
		if(isset(static::$instances[$id]))
			return static::$instances[$id];

		if(!$disableChecks && !IsPlayerConnected($id))
			return null;

		return static::$instances[$id] = new static($id);
	}

	protected function __construct($id)
	{
		$this->id = $id;
	}

	public function getName()
	{
		return GetPlayerName($this->id);
	}

	public function kick()
	{
		return Kick($this->id);
	}

	public function sendClientMessage($color, $message)
	{
		return SendClientMessage($this->id, $color, $message);
	}
}

$callbackNames = array(
	'Player' =>
		array(
			'ClickMap', 'Spawn', 
		),
);

foreach($callbackNames as $prefix => $cbs)
{
	foreach($cbs as $callbackName)
	{
		Event::on($prefix.$callbackName, function($player) use($callbackName) {
			$args = func_get_args();
			array_unshift($args, $callbackName);
				
			call_user_func_array(array($player, 'fire'), $args);
		});
	}
}


/*
Usage:
Player::find(123)->on('Spawn', function($player) {
	$player->kick();
});
*/