<?php

// To be used with Player class only
class RaceCheckpoint
{
	public static $instances = array();

	protected $player = null;
	protected $type = null;
	protected $x = null;
	protected $y = null;
	protected $z = null;
	protected $nextx = null;
	protected $nexty = null;
	protected $nextz = null;
	protected $size = null;
	protected $onEnter = null;
	protected $onLeave = null;


	public static function createForPlayer($player, $type, $x, $y, $z,
		$nextx, $nexty, $nextz, $size, $onEnter = null, $onLeave = null)
	{
		SetPlayerRaceCheckpoint($player->id, $type, $x, $y, $z, $nextx, $nexty, $nextz, $size);

		return static::$instances[$player->id] = new static($player, $x, $y, $z, $nextx, $nexty, $nextz, $size, $onEnter, $onLeave);
	}

	public static function destroyForPlayer($player)
	{
		if(isset(static::$instances[$player->id]))
		{
			static::$instances[$player->id]->destroy();
		}
	}

	public static function handleEnter($player)
	{
		if(isset(static::$instances[$player->id]))
		{
			$instance = static::$instances[$player->id];

			if(isset($instance->onEnter))
				call_user_func($instance->onEnter, $player, $instance);
		}
	}

	public static function handleLeave($player)
	{
		if(isset(static::$instances[$player->id]))
		{
			$instance = static::$instances[$player->id];

			if(isset($instance->onLeave))
				call_user_func($instance->onLeave, $player, $instance);
		}
	}	

	public function destroy()
	{
		DisablePlayerRaceCheckpoint($this->player->id);
		unset(static::$instances[$this->player->id]);
	}

	protected function __construct($player, $type, $x, $y, $z, $nextx, $nexty, $nextz, $size, $onEnter, $onLeave)
	{
		$this->player = $player;

		$this->type = $type;

		$this->x = $x;
		$this->y = $y;
		$this->z = $z;

		$this->nextx = $nextx;
		$this->nexty = $nexty;
		$this->nextz = $nextz;

		$this->size = $size;

		$this->onEnter = $onEnter;
		$this->onLeave = $onLeave;
	}

	public function on($name, $callback)
	{
		if($name == "Enter")
		{
			$this->onEnter = $callback;
			return true;
		}

		if($name == "Leave")
		{
			$this->onLeave = $callback;
			return true;
		}

		throw new Exception("Event: $name not found on RaceCheckpoint class!");
	}

	public function setPos($x, $y, $z, $nextx = null, $nexty = null, $nextz = null, $size = null)
	{
		if(!isset($size)) $size = $this->size;
		if(!isset($nextx)) $nextx = $this->nextx;
		if(!isset($nexty)) $nexty = $this->nexty;
		if(!isset($nextz)) $nextz = $this->nextz;

		SetPlayerRaceCheckpoint($this->player->id, $this->type, $x, $y, $z, $nextx, $nexty, $nextz, $size);
	}
}

Event::on('PlayerEnterRaceCheckpoint', array('RaceCheckpoint', 'handleEnter'));
Event::on('PlayerLeaveRaceCheckpoint', array('RaceCheckpoint', 'handleLeave'));