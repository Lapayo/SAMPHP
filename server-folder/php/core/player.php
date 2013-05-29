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
}

/*
Usage:
Player::find(123)->on('Spawn', function($player) {
	$player->kick();
});
*/