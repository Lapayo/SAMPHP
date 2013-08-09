<?php
class Timer
{
	protected static $instances = array();

	protected $id;

	public static function find($id)
	{
		if(isset(static::$instances[$id]))
			return static::$instances[$id];

		return static::$instances[$id] = new static($id);
	}

	public static function create($callback, $interval, $repeating)
	{
		$id = SetTimer($callback, $interval, $repeating);

		return static::$instances[$id] = new static($id);
	}

	public function destroy()
	{
		KillTimer($this->id);

		unset(static::$instances[$this->id]);

		$this->id = -1;
	}

	protected function __construct($id)
	{
		$this->id = $id;
	}
}
