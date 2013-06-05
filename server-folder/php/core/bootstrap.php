<?php
//DIRS
define('CORE_DIR', dirname(__FILE__).'/');
define('PHP_DIR', CORE_DIR..'../');
define('SAMP_DIR', CORE_DIR.'../../');
define('SAMP_FILES_DIR', CORE_DIR.'../../scriptfiles/');

set_include_path(get_include_path() . PATH_SEPARATOR . PHP_DIR . PATH_SEPARATOR . CORE_DIR);

require_once 'helpers.php';
require_once 'callbacks.php';
require_once 'modelevent.php';
require_once 'namedinstance.php';
require_once 'event.php';
require_once 'storage.php';

require_once 'commandtext.php';
require_once 'rconcommand.php';

require_once 'player.php';
require_once 'vehicle.php';
require_once 'pickup.php';

require_once 'gangzone.php';

require_once 'checkpoint.php';
require_once 'racecheckpoint.php';


require_once 'text3d.php';
require_once 'playertext3d.php';

require_once 'menu.php';
require_once 'dialog.php';
require_once 'server.php';
require_once 'playerobject.php';
require_once 'object.php';
require_once 'playertextdraw.php';
require_once 'textdraw.php';
