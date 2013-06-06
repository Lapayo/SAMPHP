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
		PlayerTextDrawLetterSize($this->playerId, $this->textId, $x, $y);

		return $this;
	}

	public static function setTextSize($x, $y)
	{
		PlayerTextDrawTextSize($this->playerId, $this->textId, $x, $y);

		return $this;
	}

	public static function setAlignment($alignment)
	{
		PlayerTextDrawAlignment($this->playerId, $this->textId, $alignment);

		return $this;
	}

	public static function setColor($color)
	{
		PlayerTextDrawColor($this->playerId, $this->textId, $color);

		return $this;
	}

	public static function useBox($use = true)
	{
		PlayerTextDrawUseBox($this->playerId, $this->textId, $use);

		return $this;
	}

	public static function setBoxColor($color)
	{
		PlayerTextDrawBoxColor($this->playerId, $this->textId, $color);

		return $this;
	}

	public static function setShadow($size)
	{
		PlayerTextDrawSetShadow($this->playerId, $this->textId, $size);

		return $this;
	}

	public static function setOutline($size)
	{
		PlayerTextDrawSetOutline($this->playerId, $this->textId, $size);

		return $this;
	}

	public static function setBackgroundColor($color)
	{
		PlayerTextDrawBackgroundColor($this->playerId, $this->textId, $color);

		return $this;
	}

	public static function setFont($font)
	{
		PlayerTextDrawFont($this->playerId, $this->textId, $font);

		return $this;
	}

	public static function setProportional($set = true)
	{
		PlayerTextDrawSetProportional($this->playerId, $this->textId, $set);

		return $this;
	}

	public static function setSelectable($set = true)
	{
		PlayerTextDrawSetSelectable($this->playerId, $this->textId, $set);

		return $this;
	}

	public static function hide()
	{
		PlayerTextDrawHide($this->playerId, $this->textId);

		return $this;
	}

	public static function show()
	{
		PlayerTextDrawShow($this->playerId, $this->textId);

		return $this;
	}

	public static function setString($string)
	{
		PlayerTextDrawSetString($this->playerId, $this->textId, $string);

		return $this;
	}

	public static function setPreviewModel($modelIndex)
	{
		PlayerTextDrawSetPreviewModel($this->playerId, $this->textId, $modelIndex);

		return $this;
	}

	public static function setPreviewRot($x, $y, $z, $zoom = 1.0)
	{
		PlayerTextDrawSetPreviewRot($this->playerId, $this->textId, $x, $y, $z, $zoom);

		return $this;
	}

	public static function setPreviewVehCol($color1, $color2)
	{
		PlayerTextDrawSetPreviewVehCol($this->playerId, $this->textId, $color1, $color2);

		return $this;
	}
}