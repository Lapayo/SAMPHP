<?php

class CommandText
{
	protected static $commands;

	public static function register($commands, $callback)
	{
		foreach((array) $commands as $command)
		{
			$command = strtolower('/'.ltrim($command, '/'));
			static::$commands[$command] = $callback;
		}
	}

	public static function handleCommand($player, $commandStr)
	{
		$splittedParams = explode(' ', $commandStr);

		$command = strtolower($splittedParams[0]);

		if(!isset(static::$commands[$command])) return false;

		array_shift($splittedParams);

		$params = implode(' ', $splittedParams);

		call_user_func(static::$commands[$command], $player, $params, $splittedParams);

		return true;
	}
}

Event::on('PlayerCommandText', array('CommandText', 'handleCommand'));