<?php
class Event
{
	protected static $events = array(
		'on' => array(),
		'after' => array(),
	);
	
	
	public static function on($eventId, $eventFunction)
	{
		if(is_callable($eventFunction))
			static::$events['on'][$eventId][] = $eventFunction;
	}
	
	public static function after($eventId, $eventFunction)
	{
		if(is_callable($eventFunction))
			static::$events['after'][$eventId][] = $eventFunction;
	}
	
	public static function fire($eventId)
	{
		$args = func_get_args();
		unset($args[0]);
		
		$result = null;

		if(isset(static::$events['on'][$eventId]))
		{
			foreach(static::$events['on'][$eventId] as $callback)
			{
				call_user_func_array($callback, $args);
			}			
		}

		if(isset(static::$events['after'][$eventId]))
		{
			foreach(static::$events['after'][$eventId] as $callback)
				call_user_func_array($callback, $args);			
		}

		return $result;
	}

	public static function until($eventId, $expected = true)
	{
		$args = func_get_args();
		unset($args[0]);

		if(isset(static::$events['on'][$eventId]))
		{
			foreach(static::$events['on'][$eventId] as $callback)
			{
				$res = call_user_func_array($callback, $args);
				
				if($res !== $expected)
					return $res;
			}			
		}

		if(isset(static::$events['after'][$eventId]))
		{
			foreach(static::$events['after'][$eventId] as $callback)
			{
				$res = call_user_func_array($callback, $args);
				
				if(!is_null($res) && $res !== $expected)
					return $res;
			}				
		}

		return $expected;
	}

	public static function cancelWithPrefix($prefix)
	{
		$prefixLength = strlen($prefix);

		foreach(static::$events['on'] as $name => &$callbacks)
		{
			if(substr($name, 0, $prefixLength) == $prefix)
				unset(static::$events['on'][$name]);
		}

		foreach(static::$events['after'] as $name => &$callbacks)
		{
			if(substr($name, 0, $prefixLength) == $prefix)
				unset(static::$events['after'][$name]);
		}
	}
}


/*
trait ModelEventHandler
{
	public function on($name, $callback)
	{
		$name = $this->callbackName($name);

		Event::on($name, $callback);
	}

	public function fire($name)
	{
		$args = func_get_args();
		$args[0] = $this->callbackName($name);

		return call_user_func_array(array('Event', 'fire'), $args);
	}

	public function cancelAll()
	{
		Event::cancelWithPrefix($this->eventPrefix.'.'.$this->id);
	}

	protected function callbackName($name)
	{
		return $this->eventPrefix.'.'.$this->id.'.'.$name;
	}
}
*/
?>