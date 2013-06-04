<?php
class PlayerTextDraw
{
	protected static $instances = array();

	protected $playerId;
	protected $textId;

	public static function findForPlayer($player, $text)
	{
		if(isset(static::$instances[$player->id][$id]))
			return static::$instances[$player->id][$id];

		return static::$instances[$player->id][$id] = new static($player->id, $id);
	}

	public static function create($player, $x, $y, $text)
	{
		$id = CreatePlayerTextDraw($player->id, $x, $y, $text);

		return static::$instances[$id] = new static($player->id, $id, $model);
	}

	public function destroy()
	{
		PlayerTextDrawDestroy($this->playerId, $this->textId);

		unset(static::$instances[$this->playerId][$this->textId]);

		$this->playerId = INVALID_PLAYER_ID;
		$this->textId = INVALID_TEXT_DRAW;
	}

	protected function __construct($playerid, $textid)
	{
		$this->playerId = $playerid;
		$this->textId = $drawid;
	}

	public static function setLetterSize($x, $y)
	{
		return PlayerTextDrawLetterSize($this->playerId, $this->textId, $x, $y);
	}

	public static function setTextSize($x, $y)
	{
		return PlayerTextDrawTextSize($this->playerId, $this->textId, $x, $y);
	}

	public static function setAlignment($alignment)
	{
		return PlayerTextDrawAlignment($this->playerId, $this->textId, $alignment);
	}

	public static function setColor($color)
	{
		return PlayerTextDrawColor($this->playerId, $this->textId, $color);
	}

	public static function useBox($use = true)
	{
		return PlayerTextDrawUseBox($this->playerId, $this->textId, $use);
	}

	public static function setBoxColor($color)
	{
		return PlayerTextDrawBoxColor($this->playerId, $this->textId, $color);
	}

	public static function setShadow($size)
	{
		return PlayerTextDrawSetShadow($this->playerId, $this->textId, $size);
	}

	public static function setOutline($size)
	{
		return PlayerTextDrawSetOutline($this->playerId, $this->textId, $size);
	}

	public static function setBackgroundColor($color)
	{
		return PlayerTextDrawBackgroundColor($this->playerId, $this->textId, $color);
	}

	public static function setFont($font)
	{
		return PlayerTextDrawFont($this->playerId, $this->textId, $font);
	}

	public static function setProportional($set = true)
	{
		return PlayerTextDrawSetProportional($this->playerId, $this->textId, $set);
	}

	public static function setSelectable($set = true)
	{
		return PlayerTextDrawSetSelectable($this->playerId, $this->textId, $set);
	}

	public static function hide()
	{
		return PlayerTextDrawHide($this->playerId, $this->textId);
	}

	public static function show()
	{
		return PlayerTextDrawShow($this->playerId, $this->textId);
	}

	public static function setString($string)
	{
		return PlayerTextDrawSetString($this->playerId, $this->textId, $string);
	}

	public static function setPreviewModel($modelIndex)
	{
		return PlayerTextDrawSetPreviewModel($this->playerId, $this->textId, $modelIndex);
	}

	public static function setPreviewRot($x, $y, $z, $zoom = 1.0)
	{
		return PlayerTextDrawSetPreviewRot($this->playerId, $this->textId, $x, $y, $z, $zoom);
	}

	public static function setPreviewVehCol($color1, $color2)
	{
		return PlayerTextDrawSetPreviewVehCol($this->playerId, $this->textId, $color1, $color2);
	}
}