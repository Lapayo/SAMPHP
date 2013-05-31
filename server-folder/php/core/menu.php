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
	protected $colwidth;
	protected $rows = array(array(),array());

	public static function find($id, $disableChecks)
	{
		if($id instanceof Menu)
			return $id;

		if(isset(static::$instances[$id]))
			return static::$instances[$id];

		return null;
	}
	public static function create($title, $x, $y, $col1width, $col2width = null)
	{
		$columns = $col2width===null?1:2;
		$id = CreateMenu($title,$columns,$x,$y,$col1width,$col2width);
		return static::$instances[$id] = new static($id, $title, $x, $y, $col1width, $col2width);
	}

	protected function __construct($id, $title, $x, $y, $col1width, $col2width)
	{
		$this->id = $id;
		$this->title = $title;
		$this->x = $x;
		$this->y = $y;
		$this->columns = $columns;
		$this->colwidth = array($col1width, $col2width);
	}


	public function destroy()
	{
		DestroyMenu($this->id);
		unset($instances[$this->id]);
		$this->id = INVALID_MENU;
	}

	public function addRow(/*text, text, value*/)
	{
		$arguments = func_get_args();
		$arguments_num = func_num_args();
		if($this->columns == 1 && $arguments_num >= 1)
		{
			$this->addItem(0,$arguments[0],isset($arguments[1])?$arguments[1]:null);
		}
		else if($this->columns == 2 && $arguments_num >=2)
		{
			$this->addItem(0,$arguments[0],isset($arguments[2])?$arguments[2]:null);
			$this->addItem(1,$arguments[1],isset($arguments[3])?$arguments[3]:null);
		}
	}

	public function addItem($column, $text, $value=NULL)
	{
		$this->rows[$column][]=array('text'=>$text, 'value'=>$value);
		AddMenuItem($this->id, $column, $text);

	}
	public function setColumnHeader($column, $text)
	{
		SetMenuColumnHeader($this->id, $column, $text);
	}

}
