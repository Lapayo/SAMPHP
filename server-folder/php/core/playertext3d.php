<?php
class PlayerText3D
{
	protected static $instances = array();

	protected $id;
	protected $player;

	public static function find($id)
	{
		if($id instanceof PlayerText3D)
			return $id;

		if(isset(static::$instances[$id]))
			return static::$instances[$id];

		return null;
	}

	public static function create($player, $text, $color, $x, $y, $z, $drawDistance = 100.0,
		$attachedplayer = INVALID_PLAYER_ID, $attachedvehicle = INVALID_VEHICLE_ID, $virtualworld = 0, $testLOS = false)
	{
		$id = CreatePlayer3DTextLabel($player->id, $text, $color, $x, $y, $z, $drawDistance, $attachedplayer, $attachedvehicle, $virtualworld, $testLOS);

		return static::$instances[$id] = new static($player, $id);
	}

	public function destroy()
	{
		DeletePlayer3DTextLabel($this->player->id, $this->id);
		unset(static::$instances[$this->id]);

		$this->id = INVALID_3DTEXT_ID;
	}

	protected function __construct($player, $id)
	{
		$this->id = $id;
		$this->player = $player;
	}

	public function setText($color, $text)
	{
		return UpdatePlayer3DTextLabelText($this->player->id, $this->id, $color, $text);
	}

	public function updateText($color, $text)
	{
		return UpdatePlayer3DTextLabelText($this->player->id, $this->id, $color, $text);
	}
}
