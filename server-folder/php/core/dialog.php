<?php
class Dialog
{
	use ModelEvent;

	protected static $minDialogId = 30000;
	protected static $maxDialogId = 32767;

	protected static $instances = array();
	protected $id;
	protected $player; //Player who is currently using the Dialog
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
		foreach(static::$instances as $instance)
			if($instance->id === $id)
				return $instance;
	}

	public static function findForPlayer($player)
	{
		foreach(static::$instances as $instance)
			if($instances->player === $player)
				return $instance;
	}

	protected function __construct($style, $caption, $button1, $button2)
	{
		$this->id = sizeof(static::$instances);
		$this->style = $style;
		$this->caption = $caption;
		$this->button = array(1 => $button1, 0 => $button2);
	}

	public function addListItem($itemtext, $value=null)
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
		for($id = static::$minDialogId; static::find($id) instanceof Dialog; $id++);

		if($id >= static::$maxDialogId)
		{
			echo "Max dialogid: ".static::$maxDialogId." reached!";
			return false;
		}
		$this->id = $id;
		$this->player = $player;
		if($this->style == DIALOG_STYLE_LIST)
		{
			unset($info);

			foreach($this->info as $item)
				$info[] = $item['item'];

			$info = implode("\n", $info);
		}
		ShowPlayerDialog($player->id, $this->id, $this->style, $this->caption, $info, $this->button[1], $this->button[0]);
		return $this;
	}

	private function setIdToNull()
	{
		$this->id = null;
		$this->player = null;
	}

	public static function handleUnexpectedClosing($player)
	{
		if(($dialog=static::findForPlayer($player)) instanceof Dialog)
			$dialog->setIdToNull();
	}

	public static function handleResponse($player, $dialogid, $response, $listitem, $inputtext)
	{
		$dialog = static::find($dialogid);
		if($dialog->style == DIALOG_STYLE_LIST)
			$value = $listitem;
			if($dialog->info[$listitem]['value'] !== null)
				$value = $dialog->info[$listitem]['value'];
		else
			$value = null;
		$dialog->setIdToNull();
		$dialog->fire('Response', $player, $dialog, $inputtext, $dialog->button[$response], $value);
	}

}

Event::on('DialogResponse', array('Dialog', 'handleResponse'));
Event::on('PlayerDisconnect',array('Dialog','handleUnexpectedClosing'));
