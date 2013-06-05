<?php

trait Storage
{
	protected $__data = array();

	public function __set($key, $value)
	{
		return $this->__data[$key] = $value;
	}

	public function __get($key)
	{
		return $this->__data[$key];
	}

	public function __isset($key)
	{
		return isset($this->__data[$key]);
	}
}