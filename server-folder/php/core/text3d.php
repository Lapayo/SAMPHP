<?php
class Text3D
{
	protected static $instances = array();

	protected $id;

	public static function find($id)
	{
		if($id instanceof Text3D)
			return $id;

		if(isset(static::$instances[$id]))
			return static::$instances[$id];

		return static::$instances[$id] = new static($id);
	}

	public static function create($text, $color, $x, $y, $z, $drawDistance = 100.0, $virtualworld = 0, $testLOS = false)
	{
		$id = Create3DTextLabel($text, $color, $x, $y, $z, $drawDistance, $virtualworld, $testLOS);

		return static::$instances[$id] = new static($id);
	}

	public function destroy()
	{
		Delete3DTextLabel($this->id);
		unset(static::$instances[$this->id]);

		$this->id = INVALID_3DTEXT_ID;
	}

	protected function __construct($id)
	{
		$this->id = $id;
	}

	public function attachToPlayer($player, $dX = 0.0, $dY = 0.0, $dZ = 0.0)
	{
		return Attach3DTextLabelToPlayer($this->id, $player->id, $dX, $dY, $dZ);
	}

	public function attachToVehicle($vehicle, $dX = 0.0, $dY = 0.0, $dZ = 0.0)
	{
		return Attach3DTextLabelToVehicle($this->id, $vehicle->id, $dX, $dY, $dZ);
	}

	public function setText($color, $text)
	{
		return Update3DTextLabelText($this->id, $color, $text);
	}

	public function updateText($color, $text)
	{
		return Update3DTextLabelText($this->id, $color, $text);
	}
}
