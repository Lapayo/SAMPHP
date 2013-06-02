<?php
class Dialog
{
  use ModelEvent;

	protected static $instances = array();
	protected $id;
	protected $style;
	public $caption;
	public $info;
	protected $buttons=array();

	public static function create($style, $caption, $button1, $button2 = null)
	{
		return static::$instances[] = new static($style, $caption, $button1, $button2);
	}

	public static function find($id)
	{
		foreach(static::$instances as $key => $instance)
		{
			if($instance->id === $id)
				return static::$instances[$key];
		}
	}

	protected function __construct($style, $caption, $button1, $button2)
	{
		$this->id = sizeof(static::$instances);
		$this->style = $style;
		$this->caption = $caption;
		$this->button = array(1 => $button1, 0 => $button2);
	}

	public function addListItem($itemtext,$value=null)
	{
		if($this->style == DIALOG_STYLE_LIST)
			$this->info[] = array('item' => $itemtext, 'value' => $value);

		return $this;
	}

	public function setInfo($info)
	{
		if($style != DIALOG_STYLE_LIST)
			$this->info = $info;
		return $this;
	}

	public function setCaption($caption)
	{
		$this->caption = $caption;
		return $this;
	}

	public function showPlayer($player)
	{
		$info = $this->info;
		
		if($this->style == DIALOG_STYLE_LIST)
		{
			unset($info);

			foreach($this->info as $item)
			{
				$info[] = $item['item'];
			}
			$info = implode('\n', $info);
		}


		ShowPlayerDialog($player->id, $this->id, $this->style, $this->caption, $info, $this->button[1], $this->button[0]);

		return $this;
	}

	public static function handleResponse($player, $dialogid, $response, $listitem, $inputtext)
	{
		$dialog = Dialog::find($dialogid);

		echo 'Dialog: '.$dialog->id.' showed to Player: '.$player->id;
		echo 'Selected listitem = '.$listitem;
		echo 'Selected button = '.$response;

		if($dialog->style == DIALOG_STYLE_LIST)
			$listvalue = $dialog->info[$listitem];
		else
			$listvalue = $listitem = null;

		Event::fire('Response', $player, $dialog, $inputtext, $dialog->button[$response], $listitem, $listvalue);
	}

}

Event::on('DialogResponse', array('Dialog', 'handleResponse'));
