<?php
class Pickup
{
	use ModelEvent;

	protected static $instances = array();

	protected $id;
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

		return null;
	}

	public static function create($model, $type, $x, $y, $z, $virtualworld = 0)
	{
		$id = CreatePickup($model, $type, $x, $y, $z, $virtualworld);

		return static::$instances[$id] = new static($id, $model, $type, $x, $y, $z, $virtualworld);
	}

	public function recreate()
	{
		$this->destroy();

		$this->id = CreatePickup($this->model, $this->type, $this->x, $this->y, $this->z, $this->virtualworld);

		static::$instances[$this->id] = $this;	
	}

	protected function __construct($id, $model, $type, $x, $y, $z, $virtualworld)
	{
		$this->id = $id;
		$this->model = $model;
		$this->type = $type;
		$this->x = $x;
		$this->y = $y;
		$this->z = $z;
		$this->virtualworld = $virtualworld;

	}

	public function getId()
	{
		return $this->id;
	}

	public function getModelId()
	{
		return $this->model;
	}

	public function getType()
	{
		return $this->type;
	}

	public function getPos()
	{
		return (object) array('x' => $this->x, 'y' => $this->y, 'z' => $this->z);
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

	public function setModelId($model)
	{
		$this->model = $model;

		$this->recreate();
	}

	public function setType($type)
	{
		$this->type = $type;

		$this->recreate();
	}

	public function setVirtualworld($virtualworld)
	{
		$this->virtualworld = $virtualworld;

		$this->recreate();
	}

	public function destroy()
	{
		DestroyPickup($this->id);
		unset(static::$instances[$this->id]);

		$this->id = INVALID_PICKUP_ID;
	}
}