<?php

// To be used with Player class only
class Checkpoint
{
	public static $instances = array();

	protected $player = null;
	protected $x = null;
	protected $y = null;
	protected $z = null;
	protected $size = null;
	protected $onEnter = null;
	protected $onLeave = null;


	public static function createForPlayer($player, $x, $y, $z, $size, $onEnter = null, $onLeave = null)
	{
		SetPlayerCheckpoint($player->id, $x, $y, $z, $size);

		return static::$instances[$player->id] = new static($player, $x, $y, $z, $size, $onEnter, $onLeave);
	}

	public static function destroyForPlayer($player)
	{
		if(isset(static::$instances[$player->id]))
		{
			static::$instances[$player->id]->destroy();
		}
	}

	public static function findForPlayer($player)
	{
		if(isset(static::$instances[$player->id]))
		{
			return static::$instances[$player->id];
		}

		return null;
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
		DisablePlayerCheckpoint($player->id);
		unset(static::$instances[$player->id]);
	}

	protected function __construct($player, $x, $y, $z, $size, $onEnter, $onLeave)
	{
		$this->player = $player;

		$this->x = $x;
		$this->y = $y;
		$this->z = $z;

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

		throw new Exception("Event: $name not found on Checkpoint class!");
	}

	public function setPos($x, $y, $z, $size = null)
	{
		if(!isset($size)) $size = $this->size;

		SetPlayerCheckpoint($this->player->id, $x, $y, $z, $size);
	}

	public function isPlayerInRange($range = 50.0, $player = null)
	{
		if(!isset($player))
			$player = $this->player;

		return $player->getDistanceFromPoint($this->x, $this->y, $this->z) <= $range;
	}
}

Event::on('PlayerEnterCheckpoint', array('Checkpoint', 'handleEnter'));
Event::on('PlayerLeaveCheckpoint', array('Checkpoint', 'handleLeave'));