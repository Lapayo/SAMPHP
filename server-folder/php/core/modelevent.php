<?php
trait ModelEvent
{
	protected $events = array('on' => array());
	
	
	public function on($name, $callback)
	{
		if(is_callable($callback))
			$this->events['on'][$name][] = $callback;

		return $this;
	}
	
	public function fire($name /*, ... */)
	{
		$args = func_get_args();
		unset($args[0]);
		
		if(isset($this->events['on'][$name]))
		{
			foreach($this->events['on'][$name] as $callback)
				call_user_func_array($callback, $args);			
		}
	}

	public function cancel($name)
	{
		if(isset($this->events['on'][$name]))
			unset($this->events['on'][$name]);
	}

	public function cancelAll()
	{
		$this->events['on'] = array();
	}
}
