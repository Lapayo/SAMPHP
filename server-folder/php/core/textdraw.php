<?php
class PlayerText
{
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
		$id = CreateTextDraw($x, $y, $text);

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

	public static function setLetterSize($x, $y)
	{
		return TextDrawLetterSize($this->id, $x, $y);
	}

	public static function setTextSize($x, $y)
	{
		return TextDrawTextSize($this->id, $x, $y);
	}

	public static function setAlignment($alignment)
	{
		return TextDrawAlignment($this->id, $alignment);
	}

	public static function setColor($color)
	{
		return TextDrawColor($this->id, $color);
	}

	public static function useBox($use = true)
	{
		return TextDrawUseBox($this->id, $use);
	}

	public static function setBoxColor($color)
	{
		return TextDrawBoxColor($this->id, $color);
	}

	public static function setShadow($size)
	{
		return TextDrawSetShadow($this->id, $size);
	}

	public static function setOutline($size)
	{
		return TextDrawSetOutline($this->id, $size);
	}

	public static function setBackgroundColor($color)
	{
		return TextDrawBackgroundColor($this->id, $color);
	}

	public static function setFont($font)
	{
		return TextDrawFont($this->id, $font);
	}

	public static function setProportional($set = true)
	{
		return TextDrawSetProportional($this->id, $set);
	}

	public static function setSelectable($set = true)
	{
		return TextDrawSetSelectable($this->id, $set);
	}

	public static function hideForAll()
	{
		return TextDrawHideForAll($this->id);
	}

	public static function showForAll()
	{
		return TextDrawShowForAll($this->id);
	}

	public static function hideForPlayer($player)
	{
		return TextDrawHideForPlayer($player->id, $this->id);
	}

	public static function showForPlayer($player)
	{
		return TextDrawShowForPlayer($player->id, $this->id);
	}

	public static function setString($string)
	{
		return TextDrawSetString($this->id, $string);
	}

	public static function setPreviewModel($modelIndex)
	{
		return TextDrawSetPreviewModel($this->id, $modelIndex);
	}

	public static function setPreviewRot($x, $y, $z, $zoom = 1.0)
	{
		return TextDrawSetPreviewRot($this->id, $x, $y, $z, $zoom);
	}

	public static function setPreviewVehCol($color1, $color2)
	{
		return TextDrawSetPreviewVehCol($this->id, $color1, $color2);
	}
}