<?php
class TextDraw
{
	use NamedInstance;

	protected static $instances = array();

	protected $id;

	public static function find($id)
	{
		if(isset(static::$instances[$id]))
			return static::$instances[$id];

		return static::$instances[$id] = new static($id);
	}

	public static function create($x, $y, $text)
	{
		$id = TextDrawCreate($x, $y, $text);

		return static::$instances[$id] = new static($id);
	}

	public function destroy()
	{
		TextDrawDestroy($this->id);

		unset(static::$instances[$this->id]);

		$this->id = INVALID_TEXT_DRAW;
	}

	protected function __construct($id)
	{
		$this->id = $id;
	}

	public function setLetterSize($x, $y)
	{
		TextDrawLetterSize($this->id, $x, $y);

		return $this;
	}

	public function setTextSize($x, $y)
	{
		TextDrawTextSize($this->id, $x, $y);

		return $this;
	}

	public function setAlignment($alignment)
	{
		TextDrawAlignment($this->id, $alignment);

		return $this;
	}

	public function setColor($color)
	{
		TextDrawColor($this->id, $color);

		return $this;
	}

	public function useBox($use = true)
	{
		TextDrawUseBox($this->id, $use);

		return $this;
	}

	public function setBoxColor($color)
	{
		TextDrawBoxColor($this->id, $color);

		return $this;
	}

	public function setShadow($size)
	{
		TextDrawSetShadow($this->id, $size);

		return $this;
	}

	public function setOutline($size)
	{
		TextDrawSetOutline($this->id, $size);

		return $this;
	}

	public function setBackgroundColor($color)
	{
		TextDrawBackgroundColor($this->id, $color);

		return $this;
	}

	public function setFont($font)
	{
		TextDrawFont($this->id, $font);

		return $this;
	}

	public function setProportional($set = true)
	{
		TextDrawSetProportional($this->id, $set);

		return $this;
	}

	public function setSelectable($set = true)
	{
		TextDrawSetSelectable($this->id, $set);

		return $this;
	}

	public function hideForAll()
	{
		TextDrawHideForAll($this->id);

		return $this;
	}

	public function showForAll()
	{
		TextDrawShowForAll($this->id);

		return $this;
	}

	public function hideForPlayer($player)
	{
		TextDrawHideForPlayer($player->id, $this->id);

		return $this;
	}

	public function showForPlayer($player)
	{
		TextDrawShowForPlayer($player->id, $this->id);

		return $this;
	}

	public function setString($string)
	{
		TextDrawSetString($this->id, $string);

		return $this;
	}

	public function setPreviewModel($modelIndex)
	{
		TextDrawSetPreviewModel($this->id, $modelIndex);

		return $this;
	}

	public function setPreviewRot($x, $y, $z, $zoom = 1.0)
	{
		TextDrawSetPreviewRot($this->id, $x, $y, $z, $zoom);

		return $this;
	}

	public function setPreviewVehCol($color1, $color2)
	{
		TextDrawSetPreviewVehCol($this->id, $color1, $color2);

		return $this;
	}
}