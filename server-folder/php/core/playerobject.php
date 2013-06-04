<?php
class PlayerObject
{
	protected static $instances = array();

	protected $playerId;
	protected $objectId;
	protected $model;

	public static function findForPlayer($player, $objectid)
	{
		if(isset(static::$instances[$player->id][$objectid]))
			return static::$instances[$player->id][$objectid];

		return static::$instances[$player->id][$objectid] = new static($player->id, $objectid);
	}

	public static function create($player, $model, $x, $y, $z, $rX = 0.0, $rY = 0.0, $rZ = 0.0, $drawDistance = 0.0)
	{
		$id = CreatePlayerObject($player->id, $model, $x, $y, $z, $rX, $rY, $rZ, $drawDistance);

		return static::$instances[$id] = new static($player->id, $id, $model);
	}

	public function destroy()
	{
		DestroyPlayerObject($this->playerId, $this->objectId);

		unset(static::$instances[$this->playerId][$this->objectId]);

		$this->playerId = INVALID_PLAYER_ID;
		$this->objectId = INVALID_OBJECT_ID;
	}

	protected function __construct($playerid, $objectid, $model = null)
	{
		$this->playerId = $playerid;
		$this->objectId = $objectid;
		$this->model = $model;
	}

	public function setPos($x, $y, $z)
	{
		return SetPlayerObjectPos($this->playerId, $this->objectId, $x, $y, $z);
	}

	public function getPos()
	{
		return (object) GetPlayerObjectPos($this->playerId, $this->objectId);
	}

	public function attachToVehicle($vehicle, $offsetX = 0.0, $offsetY = 0.0, $offsetZ = 0.0, $rotX = 0.0, $rotY = 0.0, $rotZ = 0.0)
	{
		return AttachPlayerObjectToVehicle($this->playerId, $this->objectId, $vehicle->id, $offsetX, $offsetY, $offsetZ, $rotX, $rotY, $rotZ);
	}

	public function attachToPlayer($attachPlayer, $offsetX = 0.0, $offsetY = 0.0, $offsetZ = 0.0, $rotX = 0.0, $rotY = 0.0, $rotZ = 0.0)
	{
		return AttachPlayerObjectToPlayer($this->playerId, $this->objectId, $attachPlayer->id, $offsetX, $offsetY, $offsetZ, $rotX, $rotY, $rotZ);
	}

	public function setRot($x, $y, $z)
	{
		return SetPlayerObjectRot($this->playerId, $this->objectId, $x, $y, $z);
	}

	public function getRot()
	{
		return (object) GetPlayerObjectRot($this->playerId, $this->objectId);
	}

	public function isValid()
	{
		return IsValidPlayerObject($this->playerId, $this->objectId);
	}

	public function move($x, $y, $z, $speed, $rotX = -1000.0, $rotY = -1000.0, $rotZ = -1000.0)
	{
		return MovePlayerObject($this->playerId, $this->objectId, $x, $y, $z, $speed, $rotX, $rotY, $rotZ);
	}

	public function stop()
	{
		return StopPlayerObject($this->playerId, $this->objectId);
	}

	public function isMoving()
	{
		return IsPlayerObjectMoving($this->playerId, $this->objectId);
	}

	public function setMaterial($materialIndex, $model, $txdname, $texturename, $color = 0)
	{
		return SetPlayerObjectMaterial($this->playerId, $this->objectId, $materialIndex, $model, $txdname, $texturename, $color);
	}

	public function setMaterialText($text, $materialindex = 0, $materialsize = OBJECT_MATERIAL_SIZE_256x128,
		$fontface = "Arial", $fontsize = 24, $bold = true, $fontcolor = 0xFFFFFFFF, $backcolor = 0, $textalignment = 0)
	{
		return SetPlayerObjectMaterialText($this->playerId, $this->objectId, $text, $materialindex, $materialsize,
			$fontface, $fontsize, $bold, $fontcolor, $backcolor, $textalignment);
	}

	public function edit()
	{
		return EditPlayerObject($this->playerId, $this->objectId);
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
