<?php
class Dialog
{
	use ModelEvent;

	protected static $instances = array();
	protected static $named = array();
	protected $style;
	public $caption;
	public $info;
	protected $buttons = array();

	const internalId = 32000;

	public static function create($style, $caption, $button1, $button2 = null)
	{
		return new static($style, $caption, $button1, $button2);
	}

	public static function createList($caption, $button1, $button2 = null)
	{
		return static::create(DIALOG_STYLE_LIST, $caption, $button1, $button2);
	}

	public static function findForPlayer($player)
	{
		return isset(static::$instances[$player->id]) ? static::$instances[$player->id] : null;
	}

	public static function named($name)
	{
		return isset(static::$named[$name]) ? static::$named[$name] : null;
	}

	public function name($name)
	{
		static::$named[$name] = $this;

		return $this;
	}

	protected function __construct($style, $caption, $button1, $button2)
	{
		$this->style = $style;
		$this->caption = $caption;
		$this->button = array(1 => $button1, 0 => $button2);
	}

	public function addListItem($itemtext, $value = null)
	{
		if($this->style == DIALOG_STYLE_LIST)
			$this->info[] = array('item' => $itemtext, 'value' => $value);
		return $this;
	}

	public function addRow($text, $value = null)
	{
		return $this->addListItem($text, $value);
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
				$info[] = $item['item'];

			$info = implode("\n", $info);
		}

		static::$instances[$player->id] = $this;

		ShowPlayerDialog($player->id, static::internalId, $this->style, $this->caption, $info, $this->button[1], $this->button[0]);

		return $this;
	}

	public static function handleResponse($player, $dialogid, $response, $listitem, $inputtext)
	{
		if($dialogid !== static::internalId) return false;

		$dialog = static::findForPlayer($player);

		if($dialog->style == DIALOG_STYLE_LIST)
		{
			$value = $listitem;

			if(isset($dialog->info[$listitem]['value']))
				$value = $dialog->info[$listitem]['value'];

			$text = $dialog->info[$listitem]['item'];

			$dialog->fire('Response', $player, $dialog, $response, $value, $text);

			if($response)
				$dialog->fire('Success', $player, $dialog, $value, $text);
			else
				$dialog->fire('Cancel', $player, $dialog, $value, $text);
		}else{
			$dialog->fire('Response', $player, $dialog, $response, $inputtext);

			if($response)
				$dialog->fire('Success', $player, $dialog, $inputtext);
			else
				$dialog->fire('Cancel', $player, $dialog, $inputtext);
		}


		return true;
	}

}

Event::on('DialogResponse', array('Dialog', 'handleResponse'));
