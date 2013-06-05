<?php
function find_path($path)
{
	if(file_exists($path)) return $path;

	if(file_exists(SAMP_FILES_DIR.$path)) return SAMP_FILES_DIR.$path;

	if(file_exists(SAMP_DIR.$path)) return SAMP_DIR.$path;

	return $path;
}