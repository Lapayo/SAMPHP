<?php
class Pickup
{
	use ModelEvent;

	protected static $instances = array();

	protected $pickupid;
	protected $modelid;
	protected $type;
	protected $x;
	protected $y;
	protected $z;
	protected $virtualworld;

	public static function find($id)
	{
		if(isset(static::$instances[$id]))
			return static::$instances[$id];

		return false;
	}

	protected function recreate()
	{
		DestroyPickup($this->pickupid);
		$this->pickupid = CreatePickup($this->model, $this->type, $this->x, $this->y, $this->z, $this->virtualworld);			
	}

	function __construct($model, $type, $x, $y, $z, $virtualworld)
	{
		$this->pickupid = CreatePickup($model, $type, $x, $y, $z, $virtualworld);
		static::$instances[$this->pickupid] = new static($id);
	}

	public function getId()
	{
		return $this->pickupid;
	}

	public function getModelId()
	{
		return $this->modelid;
	}

	public function getType()
	{
		return $this->type;
	}

	public function getPos()
	{
		return array('x' => $this->x, 'y' => $this->y, 'z' => $this->z);
	}

	public function getVirtualworld()
	{
		return $this->virtualworld;
	}

	public function setPos($x, $y, $z)
	{
		$this->x = $x;
		$this->y = $y;
		$this->z = $z;
		$this->recreate();
	}	

	public function setModelId($modelid)
	{
		$this->modelid = $modelid;
		$this->recreate();
	}

	public function setType($type)
	{
		$this->type = $type;
	}

	public function setVirtualworld($virtualworld)
	{
		$this->virtualworld = $virtualworld;
	}

	function __destruct()
	{
		DestroyPickup($this->pickupid);
		unset(static::$instances[$this->pickupid]);
	}
}