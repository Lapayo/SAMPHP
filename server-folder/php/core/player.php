<?php

class Player
{
	use ModelEvent;

	protected static $instances = array();

	public $id;

	public static function find($id, $disableChecks = false)
	{
		if($id instanceof Player)
			return $id;

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

	public function isStreamedIn($forPlayer)
	{
		return IsPlayerStreamedIn($this->id, Player::find($forPlayer)->id);
	}

	public function getPos()
	{
		return (object) GetPlayerPos($this->id);
	}

	public function setPos($x, $y, $z)
	{
		return SetPlayerPos($this->id, $x, $y, $z);
	}

	public function getFacingAngle()
	{
		return GetPlayerFacingAngle($this->id);
	}

	public function setZAngle($angle)
	{
		return SetPlayerZAngle($this->id, $angle);
	}

	public function putInVehicle($vehicle, $seat = 0)
	{
		return PutPlayerInVehicle($this->id, Vehicle::find($vehicle)->id, $seat);
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


$callbackNames = array();

foreach($callbackList as $callback)
{
	$prefix = "OnPlayer";
	$prefix_len = strlen($prefix);

	if(substr($callback, 0, $prefix_len) == $prefix)
	{
		$callbackNames[$callback] = substr($callback, $prefix_len);
	}
}

foreach($callbackNames as $extern => $intern)
{
	Event::on($extern, function($player) use($intern) {
		$args = func_get_args();
		array_unshift($args, $intern);
				
		call_user_func_array(array($player, 'fire'), $args);
	});
}


/*
Usage:
Player::find(123)->on('Spawn', function($player) {
	$player->kick();
});
*/