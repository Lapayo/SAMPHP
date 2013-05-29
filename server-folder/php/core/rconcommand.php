<?php

class RconCommand
{
	protected static $commands;

	public static function register($commands, $callback)
	{
		foreach((array) $commands as $command)
		{
			static::$commands[$command] = $callback;
		}
	}

	public static function handleCommand($commandStr)
	{
		$splittedParams = explode(' ', $commandStr);

		$command = $splittedParams[0];

		if(!isset(static::$commands[$command])) return false;

		array_shift($splittedParams);

		$params = implode(' ', $splittedParams);

		call_user_func(static::$commands[$command], $params, $splittedParams);

		return true;
	}
}

Event::on('RconCommand', array('RconCommand', 'handleCommand'));