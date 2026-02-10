<?php

function throwSome($param) {
  if($param > 0) {
	  throw new Exception();
  }
}

function danger($var, $param) { // @violation
	try {
    $nullVar = null;
    $var = fopen("webdictionary.txt", "r");
    throwSome($param);
    $nullVar = new Obj();
    fclose($var);
	} catch(Exception $e) {
		// Do nothing
	}
	$nullVar->refer();
}

function safe($var, $param) {
	try {
		$nullVar = null;
		throwSome($param);
		$var = fopen("webdictionary.txt", "r");
		$nullVar = new Obj();
		fclose($var);
	} catch(Exception $e) {
		// Do nothing
	}
	$nullVar->refer();
}

function safe2($var, $param) {
	try {
    $var = fopen("webdictionary.txt", "r");
    $nullVar = new Obj();
    fclose($var);
		throwSome($param);
	} catch(Exception $e) {
		// Do nothing
	}
	$nullVar->refer();
}
