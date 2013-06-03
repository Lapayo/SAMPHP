<?php
class Menu
{
  	use ModelEvent;

	protected static $instances = array();

	public $id;

	protected $title;
	protected $x;
	protected $y;
	protected $columns;
	protected $colWidth;
	protected $rows = array(array(), array());
	protected $headers = array();

	public static function find($id)
	{
		if($id instanceof Menu)
			return $id;

		if(isset(static::$instances[$id]))
			return static::$instances[$id];

		return null;
	}

	public static function findForPlayer($player)
	{
		return static::find(GetPlayerMenu($player->id));
	}

	public static function create($title, $x, $y, $col1width, $col2width = 0)
	{
		$columns = $col2width <= 0 ? 1 : 2;
		$id = CreateMenu($title, $columns, $x, $y, $col1width, $col2width);

		return static::$instances[$id] = new static($id, $title, $columns, $x, $y, $col1width, $col2width);
	}

	public function recreate()
	{
		$this->destroy();

		$this->id = CreateMenu($this->title, $this->columns, $this->x, $this->y, $this->colWidth[0], $this->colWidth[1]);

		static::$instances[$this->id] = $this;

		foreach($this->rows as $column => $items)
		{
			foreach($items as $item)
			{
				AddMenuItem($this->id, $column, $item['text']);
			}
		}

	}

	public function destroy()
	{
		DestroyMenu($this->id);
		unset(static::$instances[$this->id]);

		$this->id = INVALID_MENU;
	}

	protected function __construct($id, $title, $columns, $x, $y, $col1width, $col2width)
	{
		$this->id = $id;
		$this->title = $title;
		$this->columns = $columns;
		$this->x = $x;
		$this->y = $y;
		$this->colWidth = array($col1width, $col2width);
	}

	public function addRow($text1, $value1 = null, $text2 = null, $value2 = null)
	{
		$this->addItem(0, $text1, $value1);

		if($this->columns == 2)
		{
			$this->addItem(1, $text2, $value2);
		}

		return $this;

		/*
		$arguments = func_get_args();
		$arguments_num = func_num_args();

		if($this->columns == 1 && $arguments_num >= 1)
		{
			$this->addItem(0, $arguments[0], isset($arguments[1]) ? $arguments[1] : null);
		} else if($this->columns == 2 && $arguments_num >= 2)
		{
			$this->addItem(0, $arguments[0], isset($arguments[2]) ? $arguments[2] : null);
			$this->addItem(1, $arguments[1], isset($arguments[3]) ? $arguments[3] : null);
		}
		*/
	}

	public function addItem($column, $text, $value = null)
	{
		$this->rows[$column][] = array('text' => $text, 'value' => $value);

		AddMenuItem($this->id, $column, $text);

		return $this;
	}

	public function setHeader($header1, $header2 = null)
	{
		$this->setColumnHeader(0, $header1);

		if(isset($header2))
			$this->setColumnHeader(1, $header2);

		return $this;
	}

	public function setColumnHeader($column, $text)
	{
		$this->headers[$column] = $text;

		SetMenuColumnHeader($this->id, $column, $text);
	
		return $this;
	}

	public function showForPlayer($player)
	{
		ShowMenuForPlayer($this->id, $player->id);
	
		return $this;
	}

	public function hideForPlayer($player)
	{
		HideMenuForPlayer($this->id, $player->id);
	
		return $this;
	}

	public static function handleSelectedRow($player, $row)
	{
		$menu = static::findForPlayer($player);

		$value1 = $value2 = $row;

		$field1 = $menu->rows[0][$row];

		if($field1['value'] !== null)
			$value1 = $field1['value'];

		if(isset($menu->rows[1]))
		{
			$field2 = $menu->rows[1][$row];

			if($field2['value'] !== null)
				$value2 = $field2['value'];
		}

		$menu->fire('PlayerSelectedRow', $player, $value1, $value2);
		$menu->fire('Success', $player, $value1, $value2);
	}

	public static function handleExited($player)
	{
		$menu = static::findForPlayer($player);

		$menu->fire('PlayerExited', $player);
	}

}

Event::on('PlayerSelectedMenuRow', array('Menu', 'handleSelectedRow'));
Event::on('PlayerExitedMenu', array('Menu', 'handleExited'));
