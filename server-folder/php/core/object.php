<?php
class Object
{
	protected static $instances = array();

	protected $id;
	protected $model;

	public static function find($id)
	{
		if(isset(static::$instances[$id]))
			return static::$instances[$id];

		return static::$instances[$id] = new static($id);
	}

	public static function create($model, $x, $y, $z, $rX = 0.0, $rY = 0.0, $rZ = 0.0, $drawDistance = 0.0)
	{
		$id = CreateObject($model, $x, $y, $z, $rX, $rY, $rZ, $drawDistance);

		return static::$instances[$id] = new static($id, $model);
	}

	public function destroy()
	{
		DestroyObject($this->id);

		unset(static::$instances[$this->id]);

		$this->id = INVALID_OBJECT_ID;
	}

	protected function __construct($id, $model = null)
	{
		$this->id = $id;
		$this->model = $model;
	}

	public function setPos($x, $y, $z)
	{
		return SetObjectPos($this->id, $x, $y, $z);
	}

	public function getPos()
	{
		return (object) GetObjectPos($this->id);
	}

	public function attachToVehicle($vehicle, $offsetX = 0.0, $offsetY = 0.0, $offsetZ = 0.0, $rotX = 0.0, $rotY = 0.0, $rotZ = 0.0)
	{
		return AttachObjectToVehicle($this->id, $vehicle->id, $offsetX, $offsetY, $offsetZ, $rotX, $rotY, $rotZ);
	}

	public function attachToPlayer($attachPlayer, $offsetX = 0.0, $offsetY = 0.0, $offsetZ = 0.0, $rotX = 0.0, $rotY = 0.0, $rotZ = 0.0)
	{
		return AttachObjectToPlayer($this->id, $attachPlayer->id, $offsetX, $offsetY, $offsetZ, $rotX, $rotY, $rotZ);
	}

	public function attachToObject($attachObject, $offsetX = 0.0, $offsetY = 0.0, $offsetZ = 0.0, $rotX = 0.0, $rotY = 0.0, $rotZ = 0.0, $syncRotation = true)
	{
		return AttachObjectToObject($this->id, $attachObject->id, $offsetX, $offsetY, $offsetZ, $rotX, $rotY, $rotZ, $syncRotation);
	}

	public function setRot($x, $y, $z)
	{
		return SetObjectRot($this->id, $x, $y, $z);
	}

	public function getRot()
	{
		return (object) GetObjectRot($this->id);
	}

	public function isValid()
	{
		return IsValidObject($this->id);
	}

	public function move($x, $y, $z, $speed, $rotX = -1000.0, $rotY = -1000.0, $rotZ = -1000.0)
	{
		return MoveObject($this->id, $x, $y, $z, $speed, $rotX, $rotY, $rotZ);
	}

	public function stop()
	{
		return StopObject($this->id);
	}

	public function isMoving()
	{
		return IsObjectMoving($this->id);
	}

	public function setMaterial($materialIndex, $model, $txdname, $texturename, $color = 0)
	{
		return SetObjectMaterial($this->id, $materialIndex, $model, $txdname, $texturename, $color);
	}

	public function setMaterialText($text, $materialindex = 0, $materialsize = OBJECT_MATERIAL_SIZE_256x128,
		$fontface = "Arial", $fontsize = 24, $bold = true, $fontcolor = 0xFFFFFFFF, $backcolor = 0, $textalignment = 0)
	{
		return SetObjectMaterial($this->id, $text, $materialindex, $materialsize, $fontface, $fontsize, $bold, $fontcolor, $backcolor, $textalignment);
	}

	public function edit($player)
	{
		return EditObject($player->id, $this->id);
	}

	public static function select($player)
	{
		return SelectObject($player->id);
	}

	public static function cancelEdit($player)
	{
		return CancelEdit($player->id);
	}
}