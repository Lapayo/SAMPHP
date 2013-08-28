<?php
class PlayerCamera
{
	protected static $instances = array();
	protected $id = null;

	public static function findForPlayer($player)
	{
		if(!isset(static::$instances[$player->id])){
            static::$instances[$player->id] = new static($player->id);
        }
        
        return static::$instances[$player->id];
	}

	protected function __construct($playerid)
	{
		$this->id = $playerid;
	}

	public function setPos($x, $y, $z)
	{
		return SetPlayerCameraPos($this->id, $x, $y, $z);
	}

	public function getPos()
	{
		return (object) GetPlayerCameraPos($this->id);
	}

	public function setLookAt($x, $y, $z, $cut = CAMERA_CUT)
	{
		return SetPlayerCameraLookAt($this->id, $x, $y, $z, $cut);
	}

	public function setBehindPlayer()
	{
		return SetPlayerCameraBehindPlayer($this->id);
	}

	public function getFrontVector()
	{
		return (object) GetPlayerCameraFrontVector($this->id);
	}

	public function getMode()
	{
		return GetPlayerCameraMode($this->id);
	}

	public function attachToObject($object)
	{
		return AttachCameraToObject($this->id, $object->id);
	}

	public function attachToPlayerObject($playerObject)
	{
		return AttachCameraToPlayerObject($this->id, $playerObject->id);
	}

	public function interpolatePos($fromX, $fromY, $fromZ, $toX, $toY, $toZ, $time, $cut = CAMERA_CUT)
	{
		return InterpolateCameraPos($this->id, $fromX, $fromY, $fromZ, $toX, $toY, $toZ, $time, $cut);
	}

	public function interpolateLookAt($fromX, $fromY, $fromZ, $toX, $toY, $toZ, $time, $cut = CAMERA_CUT)
	{
		return InterpolateCameraLookAt($this->id, $fromX, $fromY, $fromZ, $toX, $toY, $toZ, $time, $cut);
	}

}

