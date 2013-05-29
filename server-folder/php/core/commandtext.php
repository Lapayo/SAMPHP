<?php

class CommandText
{
	protected static $commands;

	public static function register($commands, $callback)
	{
		foreach((array) $commands as $command)
		{
			$command = '/'.ltrim($command, '/');
			static::$commands[$command] = $callback;
		}
	}

	public static function handleCommand($player, $commandStr)
	{
		$splittedParams = explode(' ', $commandStr);

		$command = $splittedParams[0];

		array_shift($splittedParams);

		$params = implode(' ', $splittedParams);

		if(!isset(static::$commands[$command])) return false;

		call_user_func(static::$commands[$command], $player, $params, $splittedParams);

		return true;
	}
}

Event::on('PlayerCommandText', array('CommandText', 'handleCommand'));