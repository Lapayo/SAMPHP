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
 * TO BE ADDED:
 * "ref_string", adds a reference for the string and a integer for the buffer size to the parameters of the function  (like you did with new val[100];) (=> u,l)
 * "ref_string_fixed:size", example "ref_string_len:100" like ref_string with fixed buffer size (100 byte in this example)	(=> u,l = size)
 * "ref_float"/"ref_double"	(=> v)
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

	foreach($args as $arg)
	{
		switch($arg)
		{
			case "long": case "int": case "integer": case "bool":
				$descriptors .= "l";
				$values[] = null;
				break;
			case "string":
				$descriptors .= "s";
				$values[] = null;
				break;
			case "double": case "float":
				$descriptors .= "d";
				$values[] = null;
				break;
			default:
				if(StartsWith($arg, "ref_string_fixed"))
				{
					$descriptors .= "u";
					$values[] = null;
					$descriptors .= "l";
					list($key, $value) = ParamSplitKeyValue($arg);
					$values[] = $value;
				}
				elseif(StartsWith($arg, "ref_string"))
				{
					$descriptors .= "u";
					$values[] = null;
					$descriptors .= "l";
					$values[] = null;
				}
				elseif(StartsWith($arg, "ref_float"))
				{
					$descriptors .= "v";
					$values[] = null;
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

		if(!is_null($v)) continue;	// default values are not needed in the function header

		switch($d)
		{
			case "l": case "s": case "d":
				$ps[] = '$arg'.$i;
				break;
			case "u": case "v":
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

		if(is_null($v)) continue;

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
	switch($arg)
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