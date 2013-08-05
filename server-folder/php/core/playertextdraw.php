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

		return static::$instances[$id] = new static($player->id, $id);
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
		$this->textId = $textid;
	}

	public function setLetterSize($x, $y)
	{
		PlayerTextDrawLetterSize($this->playerId, $this->textId, $x, $y);

		return $this;
	}

	public function setTextSize($x, $y)
	{
		PlayerTextDrawTextSize($this->playerId, $this->textId, $x, $y);

		return $this;
	}

	public function setAlignment($alignment)
	{
		PlayerTextDrawAlignment($this->playerId, $this->textId, $alignment);

		return $this;
	}

	public function setColor($color)
	{
		PlayerTextDrawColor($this->playerId, $this->textId, $color);

		return $this;
	}

	public function useBox($use = true)
	{
		PlayerTextDrawUseBox($this->playerId, $this->textId, $use);

		return $this;
	}

	public function setBoxColor($color)
	{
		PlayerTextDrawBoxColor($this->playerId, $this->textId, $color);

		return $this;
	}

	public function setShadow($size)
	{
		PlayerTextDrawSetShadow($this->playerId, $this->textId, $size);

		return $this;
	}

	public function setOutline($size)
	{
		PlayerTextDrawSetOutline($this->playerId, $this->textId, $size);

		return $this;
	}

	public function setBackgroundColor($color)
	{
		PlayerTextDrawBackgroundColor($this->playerId, $this->textId, $color);

		return $this;
	}

	public function setFont($font)
	{
		PlayerTextDrawFont($this->playerId, $this->textId, $font);

		return $this;
	}

	public function setProportional($set = true)
	{
		PlayerTextDrawSetProportional($this->playerId, $this->textId, $set);

		return $this;
	}

	public function setSelectable($set = true)
	{
		PlayerTextDrawSetSelectable($this->playerId, $this->textId, $set);

		return $this;
	}

	public function hide()
	{
		PlayerTextDrawHide($this->playerId, $this->textId);

		return $this;
	}

	public function show()
	{
		PlayerTextDrawShow($this->playerId, $this->textId);

		return $this;
	}

	public function setString($string)
	{
		PlayerTextDrawSetString($this->playerId, $this->textId, $string);

		return $this;
	}

	public function setPreviewModel($modelIndex)
	{
		PlayerTextDrawSetPreviewModel($this->playerId, $this->textId, $modelIndex);

		return $this;
	}

	public function setPreviewRot($x, $y, $z, $zoom = 1.0)
	{
		PlayerTextDrawSetPreviewRot($this->playerId, $this->textId, $x, $y, $z, $zoom);

		return $this;
	}

	public function setPreviewVehCol($color1, $color2)
	{
		PlayerTextDrawSetPreviewVehCol($this->playerId, $this->textId, $color1, $color2);

		return $this;
	}
}
