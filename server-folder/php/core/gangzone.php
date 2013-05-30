<?php
class GangZone
{
	protected static $instances = array();

	protected $id;

	protected $min_x;
	protected $min_y;
	protected $max_x;
	protected $max_y;

	public static function find($id)
	{
		if($id instanceof GangZone)
			return $id;

		if(isset(static::$instances[$id]))
			return static::$instances[$id];

		return static::$instances[$id] = new static($id);
	}

	public static function create($min_x, $min_y, $max_x, $max_y)
	{
		$id = GangZoneCreate($min_x, $min_y, $max_x, $max_y);

		return static::$instances[$id] = new static($id, $min_x, $min_y, $max_x, $max_y);
	}

	public function destroy()
	{
		GangZoneDestroy($this->id);
		unset(static::$instances[$this->id]);

		$this->id = INVALID_GANG_ZONE;
	}

	protected function __construct($id, $min_x = null, $min_y = null, $max_x = null, $max_y = null)
	{
		$this->id = $id;
		$this->min_x = $min_x;
		$this->min_y = $min_y;
		$this->max_x = $max_x;
		$this->max_y = $max_y;
	}

	public function showForPlayer($player, $color)
	{
		return GangZoneShowForPlayer($player->id, $this->id, $color);
	}

	public function showForAll($color)
	{
		return GangZoneShowForAll($this->id, $color);
	}

	public function hideForPlayer($player)
	{
		return GangZoneHideForPlayer($player->id, $this->id);
	}

	public function hideForAll()
	{
		return GangZoneHideForAll($this->id);
	}

	public function flashForPlayer($player, $color)
	{
		return GangZoneFlashForPlayer($player->id, $this->id, $color);
	}

	public function flashForAll($color)
	{
		return GangZoneFlashForAll($this->id, $color);
	}

	public function stopFlashForPlayer($player)
	{
		return GangZoneStopFlashForPlayer($player->id, $this->id);
	}

	public function stopFlashForAll()
	{
		return GangZoneStopFlashForAll($this->id);
	}
}
