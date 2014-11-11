<?php

class Vehicle
{
	use ModelEvent;

	protected static $instances = array();

	public $id;

	public static function find($id, $disableChecks = false)
	{
		if($id instanceof Vehicle)
			return $id;

		if(isset(static::$instances[$id]))
			return static::$instances[$id];

		if($id == INVALID_VEHICLE_ID || (!$disableChecks && GetVehicleModel($id) == 0))
			return null;

		return static::$instances[$id] = new static($id);
	}

	public static function all()
	{
		return static::$instances;
	}

	public static function createStatic($modelId, $x, $y, $z, $angle, $color1 = null, $color2 = null, $respawnDelay = null)
	{
		//Check for trains:
		if(is_null($color1))
			$color1 = rand(0, 255);

		if(is_null($color2))
			$color2 = rand(0, 255);

		if(isset($respawnDelay))
			$id = AddStaticVehicleEx($modelId, $x, $y, $z, $angle, $color1, $color2, $respawnDelay);
		else
			$id = AddStaticVehicle($modelId, $x, $y, $z, $angle, $color1, $color2);

		return static::find($id, true);
	}

	public static function create($modelId, $x, $y, $z, $angle, $color1 = null, $color2 = null, $respawnDelay = -1)
	{
		//Check for trains:
		if(is_null($color1))
			$color1 = rand(0, 255);

		if(is_null($color2))
			$color2 = rand(0, 255);

		if($modelId == 537 || $modelId == 538)
		{
			$id = AddStaticVehicleEx($modelId, $x, $y, $z, $angle, $color1, $color2, $respawnDelay);
		}else{
			$id = CreateVehicle($modelId, $x, $y, $z, $angle, $color1, $color2, $respawnDelay);
		}

		return static::find($id, true);
	}

	protected function __construct($id)
	{
		$this->id = $id;
	}

	public function destroy()
	{
		$result = DestroyVehicle($this->id);

		// Make Vehicle object invalid
		unset(static::$instances[$this->id]);
		$this->id = INVALID_VEHICLE_ID;


		return $result;
	}

	public function isStreamedIn($forPlayer)
	{
		return IsVehicleStreamedIn($this->id, Player::find($forPlayer)->id);
	}

	public function getPos()
	{
		return (object) GetVehiclePos($this->id);
	}

	public function setPos($x, $y, $z)
	{
		return SetVehiclePos($this->id, $x, $y, $z);
	}

	public function getZAngle()
	{
		return GetVehicleZAngle($this->id);
	}

	public function setZAngle($angle)
	{
		return SetVehicleZAngle($this->id, $angle);
	}

	public function getRotationQuat()
	{
		return (object) GetRotationQuat($this->id);
	}

	public function getDistanceFromPoint($x, $y, $z)
	{
		return GetVehicleDistanceFromPoint($this->id, $x, $y, $z);
	}

	public function setParamsForPlayer($player, $objective, $doorslocked)
	{
		return SetVehicleParamsForPlayer($this->id, Player::find($player)->id, $objective, $doorslocked);
	}

	public static function manualEngineAndLights()
	{
		return ManualVehicleEngineAndLights();
	}

	public function setParams($engine, $lights, $alarm, $doors, $bonnet, $boot, $objective)
	{
		return SetVehicleParamsEx($this->id, $engine, $lights, $alarm, $doors, $bonnet, $boot, $objective);
	}

	public function getParams()
	{
		return (object) GetVehicleParamsEx($this->id);
	}

	public function setToRespawn()
	{
		return SetVehicleToRespawn($this->id);
	}

	public function linkToInterior($interior)
	{
		return LinkVehicleToInterior($this->id, $interior);
	}

	public function addComponent($component)
	{
		return AddVehicleComponent($this->id, $component);
	}

	public function removeComponent($component)
	{
		return RemoveVehicleComponent($this->id, $component);
	}

	public function changeColor($color1, $color2)
	{
		return ChangeVehicleColor($this->id, $color1, $color2);
	}

	public function changePaintjob($paintjob)
	{
		return ChangeVehiclePaintjob($this->id, $paintjob);
	}

	public function setHealth($health)
	{
		return SetVehicleHealth($this->id, $health);
	}

	public function getHealth()
	{
		return GetVehicleHealth($this->id);
	}

	public function attachTrailer($trailer)
	{
		return AttachTrailerToVehicle($this->id, Vehicle::find($trailer)->id);
	}

	public function detachTrailer()
	{
		return GetVehicleHealth($this->id);
	}

	public function isTrailerAttached($trailer = null)
	{
		if(!isset($trailer))
			return IsTrailerAttachedToVehicle($this->id);
		return IsTrailerAttachedToVehicle($this->id)
			&& Vehicle::find($trailer) === $this->getTrailer();
	}

	public function getTrailer()
	{
		return Vehicle::find(GetVehicleTrailer($this->id), true);
	}

	public function setNumberPlate($plate)
	{
		return SetVehicleNumberPlate($this->id, $plate);
	}

	public function getModel()
	{
		return GetVehicleModel($this->id);
	}

	public function getComponentInSlot($slot)
	{
		return GetVehicleComponentInSlot($this->id, $slot);
	}

	public static function getComponentType($component)
	{
		return GetVehicleComponentType($component);
	}

	public function repair()
	{
		return RepairVehicle($this->id);
	}

	public function getVelocity()
	{
		return (object) GetVehicleVelocity($this->id);
	}

	public function setVelocity($x, $y, $z)
	{
		return SetVehicleVelocity($this->id, $x, $y, $z);
	}

	public function setAngularVelocity($x, $y, $z)
	{
		return SetVehicleAngularVelocity($this->id, $x, $y, $z);
	}

	public function updateDamageStatus($panels, $doors, $lights, $tires)
	{
		return UpdateVehicleDamageStatus($this->id, $panels, $doors, $lights, $tires);
	}

	public static function getModelInfo($model, $info)
	{
		return (object) GetVehicleModelInfo($model, $info);
	}

	public function getVirtualWorld()
	{
		return (object) GetVehicleVirtualWorld($this->id);
	}

	public function setVirtualWorld($world)
	{
		return SetVehicleVirtualWorld($this->id, $world);
	}

}


$callbackNames = array();

foreach($callbackList as $callback)
{
	$prefix = "OnVehicle";
	$prefix_len = strlen($prefix);

	if(substr($callback, 0, $prefix_len) == $prefix)
	{
		$callbackNames[$callback] = substr($callback, $prefix_len);
	}
}

foreach($callbackNames as $extern => $intern)
{
	Event::on($extern, function($arg1, $arg2 = null) use($intern) {
		if($arg1 instanceof Vehicle)
			$vehicle = $arg1;
		elseif($arg2 instanceof Vehicle)
			$vehicle = $arg2;
		else
			return false;
			
		$args = func_get_args();
		array_unshift($args, $intern);
				
		call_user_func_array(array($vehicle, 'fire'), $args);
	});
}
