<?php
class PlayerText3D
{
	protected static $instances = array();

	protected $id;
	protected $playerId;

	public static function find($player, $textId)
	{
		if($textId instanceof PlayerText3D)
			return $textId;

		if(isset(static::$instances[$player->id][$textId]))
			return static::$instances[$player->id][$textId];

		return null;
	}

	public static function create($player, $text, $color, $x, $y, $z, $drawDistance = 100.0,
		$attachedplayer = INVALID_PLAYER_ID, $attachedvehicle = INVALID_VEHICLE_ID, $virtualworld = 0, $testLOS = false)
	{
		$id = CreatePlayer3DTextLabel($player->id, $text, $color, $x, $y, $z, $drawDistance, $attachedplayer, $attachedvehicle, $virtualworld, $testLOS);
        if(!isset(static::$instances[$player->id])){
            static::$instances[$player->id] = array();
        }
		return static::$instances[$player->id][$id] = new static($player->id, $id);
	}

	public function destroy()
	{
		DeletePlayer3DTextLabel($this->playerId, $this->id);
		unset(static::$instances[$this->playerId][$this->id]);

		$this->id = INVALID_3DTEXT_ID;
	}

	protected function __construct($playerid, $id)
	{
		$this->id = $id;
		$this->playerId = $playerid;
	}

	public function setText($color, $text)
	{
		return UpdatePlayer3DTextLabelText($this->playerId, $this->id, $color, $text);
	}

	public function updateText($color, $text)
	{
		return UpdatePlayer3DTextLabelText($this->playerId, $this->id, $color, $text);
	}
}
