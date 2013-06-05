<?php

trait NamedInstance
{
	protected static $__named = array();

	public static function named($name)
	{
		return isset(static::$__named[$name]) ? static::$__named[$name] : null;
	}

	public function name($name)
	{
		static::$__named[$name] = $this;

		return $this;
	}
}