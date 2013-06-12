<?php
function find_path($path)
{
	if(file_exists($path)) return $path;

	if(file_exists(SAMP_FILES_DIR.$path)) return SAMP_FILES_DIR.$path;

	if(file_exists(SAMP_DIR.$path)) return SAMP_DIR.$path;

	return $path;
}


/**
 * Registering native AMX Functions:
 * $function: "functionname" | ["amxname", "phpname"]
 * following parameters describe the accepted parameters:
 * - "int"/"integer"/"long"/"bool"	(=> "l")
 * "string"					(=> "s")
 * "float"/"double"			(=> "d")
 * 
 * "ref_string", adds a reference for the string and a integer for the buffer size to the parameters of the function  (like you did with new val[100];) (=> u,l)
 * "ref_string_fixed:size", example "ref_string_len:100" like ref_string with fixed buffer size (100 byte in this example)	(=> u,l = size)
 * "ref_float"/"ref_double"	(=> v)
 * "ref_int" (=> w)
 */
function RegisterAMXNative($function, $returntype = null /*, ... */)
{
	$args = func_get_args();
	unset($args[0]);	// Remove functionname from array
	unset($args[1]);	// Remove returntype from array

	if(is_array($function))
	{
		$amxName = $function[0];
		$phpName = $function[1];
	}else{
		$amxName = $phpName = $function;
	}


	$descriptors = "";
	$values = array();
	$defaults = array();

	foreach($args as $arg)
	{
		if(is_array($arg))
		{
			$keys = array_keys($arg);
			$key = $keys[0];
			$defaultsTo = $arg[$key];
		}else{
			$key = $arg;
			$defaultsTo = null;
		}

		switch($key)
		{
			case "long": case "int": case "integer": case "bool":
				$descriptors .= "l";
				$values[] = null;
				$defaults[] = $defaultsTo;
				break;
			case "string":
				$descriptors .= "s";
				$values[] = null;
				$defaults[] = $defaultsTo;
				break;
			case "double": case "float":
				$descriptors .= "d";
				$values[] = null;
				$defaults[] = $defaultsTo;
				break;
			default:
				if(StartsWith($key, "ref_string_fixed"))
				{
					$descriptors .= "u";
					$values[] = null;
					$defaults[] = null;

					$descriptors .= "l";
					list($key, $value) = ParamSplitKeyValue($arg);
					$values[] = $value;
					$defaults[] = null;
				}
				elseif(StartsWith($key, "ref_string"))
				{
					$descriptors .= "u";
					$values[] = null;
					$defaults[] = null;

					$descriptors .= "l";
					$values[] = null;
					$defaults[] = $defaultsTo;
				}
				elseif(StartsWith($key, "ref_float"))
				{
					$descriptors .= "v";
					$values[] = null;
					$defaults[] = null;
				}elseif(StartsWith($key, "ref_int"))
				{
					$descriptors .= "w";
					$values[] = null;
					$defaults[] = null;
				}else{
					throw new Exception("Unknow type specifier: ".$arg);
				}
				break;
		}
	}

	$code = "function ".$phpName."(";
	//generate code
	$ps = array();
	for($i = 0; $i < strlen($descriptors); $i++)
	{
		$d = $descriptors[$i];
		$v = $values[$i];
		$def = $defaults[$i];

		if(!is_null($v)) continue;	// fixed values are not needed in the function header


		switch($d)
		{
			case "l": case "s": case "d":
				$append = "";
				if($def !== null)
				{
					$append .= ' = ';
					if(is_string($def) && defined($def))
					{
						$append .= $def;
					}else{
						$append .= var_export($def, true);
					}
				}
				
				$ps[] = '$arg'.$i.$append;
				
				break;
			case "u": case "v": case "w":
				$ps[] = '&$arg'.$i;
				break;
		}
	}

	$code .= implode(', ', $ps);

	$code .= ') { ';
	// add fixed values
	for($i = 0; $i < strlen($descriptors); $i++)
	{
		$v = $values[$i];
		$d = $descriptors[$i];

		if(is_null($v)) continue;

		if($d == "l" || $d == "d")
			$code .= '$arg'.$i.' = '.$v.';'."\n";
		else
			$code .= '$arg'.$i.' = "'.$v.'";'."\n";
	}

	// create callamxnative call
	$code .= ' return CallAMXNative("'.$amxName.'", "'.StringToToken($returntype).'", "'.$descriptors.'"';

	for($i = 0; $i < strlen($descriptors); $i++)
	{
		$code .= ', $arg'.$i;
	}

	$code .= ');';
	$code .= "\n}";

	eval($code);
}

function StringToToken($str)
{
	switch($str)
	{
		case "long": case "int": case "integer": case "bool":
			return "l";
		case "string":
			return "s";
		case "double": case "float":
			return "d";
	}
	return "n";
}

/**
 * I dont recommend to use CallAMXNative directly, better use RegisterAMXNative("GetPlayerSkin", "integer"); GetPlayerSkin(123);
 * CallAMXNative($function, $returntype, $param_descriptors, $arg1, $arg2, $arg3, ...)
 */

function ParamSplitKeyValue($string)
{
	return explode(":", $string);
}

function StartsWith($str, $startsWith)
{
	return substr($str, 0, strlen($startsWith)) == $startsWith;
}


function RegisterAMXNativeFromInclude($filename)
{
	$content = file_get_contents(find_path($filename));
	
	return RegisterAMXNativeFromString($content);
}

function RegisterAMXNativeFromString($content)
{
	$lines = array_map('trim', explode("\n", $content));

	while(count($lines) > 0)
	{
		$line = array_shift($lines);

		// define
		if(preg_match("/^ *\#define +([A-Za-z0-9_]+) +\(([A-Za-z0-9_: ]+)\)/", $line, $matches))
		{
			$key = $matches[1];
			$value = trim($matches[2]);

			if(StartsWith($value, "0x"))
				$value = HexToInt($value);
			elseif(StartsWith($value, "Float:"))
			{	//Cut "Float:"
				$value = trim(substr($value, 6));
				if(StartsWith($value, "0x"))
					$value = HexToFloat($value);
				else
					$value = (float) $value;
			}else{
				$value = (int) $value;
			}

			define($key, $value);
		}
		//if defined
		elseif(preg_match("/^ *#if +([!]?) *(defined) +([A-Za-z0-9_]+)/", $line, $matches))
		{
			$on = "";

			$cond = 1;
			while(count($lines) > 1)
			{
				$buffer = array_shift($lines);
				if($buffer == "#endif")
					break;
				elseif($buffer == "#else")
				{
					$cond = 0;
				}else{
					// Store line in tmp buffer
					$on[$cond] .= "\n".$buffer;
				}
			}

			if($matches[2] == "defined")
			{
				$result = defined($matches[3]);
				if($matches[1] == "!")
					$result = !$result;
			}

			RegisterAMXNativeFromString($on[$result]);
		}
		//enums
		elseif(StartsWith($line, "enum"))
		{
			$i = 0;
			while(count($lines) > 1)
			{
				$buffer = array_shift($lines);

				if($buffer == "}") break;
				
				if(preg_match("/^ *([A-Za-z0-9_]+)\,?/", $buffer, $matches))
				{
					define($matches[1], $i++);
				}
			}
		}
		//natives 
		elseif(preg_match("/^ *native +([A-Za-z0-9_]+)\(([A-Za-z0-9\_\,\&\:\[\]\-\= ]*)\)\;/", $line, $matches))
		{
			$functionName = $matches[1];

			$paramStr = $matches[2];
			$params = array();

			if(!empty($paramStr))
			{
				$params = explode(',', $matches[2]);
				$params = array_map('ParseParam', $params);
			}

			//call register native:
			$args = array($functionName, 'int');

			$skipNext = false;
			foreach($params as $param)
			{
				if($skipNext)
				{
					$skipNext = false;
					continue;
				}

				if($param['type'] == "ref_string") $skipNext = true;

				if(isset($param['default']))
				{
					$args[] = [$param['type'] => $param['default']];
				}else{
					$args[] = $param['type'];
				}
			}

			call_user_func_array("RegisterAMXNative", $args);
		}
	}
}

function ParseParam($param)
{
	$split = explode('=', $param);

	$param = trim($split[0]);

	if(count($split) > 1)
	{
		$defaultValue = trim($split[1]);
	}

	if(preg_match("#^Float:(.*)#", $param, $matches))
	{
		$type = "float";
		$name = $matches[1];
	}elseif(preg_match("#^\&Float:(.*)#", $param, $matches))
	{
		$type = "ref_float";
		$name = $matches[1];
	}elseif(preg_match("#^const (.*)\[\]#", $param, $matches))
	{
		$type = "ref_string";
		$name = $matches[1];
	}elseif(preg_match("#^(.*)\[\]#", $param, $matches))
	{
		$type = "ref_string";
		$name = $matches[1];
	}elseif(preg_match("#^\&(.*)#", $param, $matches))
	{
		$type = "ref_int";
		$name = $matches[1];
	}elseif(preg_match("#^(.*):(.*)#", $param, $matches))
	{
		$type = "int";
		$name = $matches[1];
	}elseif(preg_match("#^\&(.*):(.*)#", $param, $matches))
	{
		$type = "ref_int";
		$name = $matches[1];
	}else{
		$type = "int";
		$name = $matches[1];
	}

	$result = array(
		'name' => $name,
		'type' => $type
	);

	if(isset($defaultValue))
	{
		//only numbers allowed and consts
		if(preg_match("/[x0-9\.A-Z_\-]+/", $defaultValue))
			$result['default'] = $defaultValue;
	}

	return $result;
}

function HexToInt($strHex)
{
	return hexdec($strHex);
}

function HexToFloat($strHex) {
    $v = hexdec($strHex);
    $x = ($v & ((1 << 23) - 1)) + (1 << 23) * ($v >> 31 | 1);
    $exp = ($v >> 23 & 0xFF) - 127;
    return $x * pow(2, $exp - 23);
}