<?php
$var = null;
try {
  throw new MyException("abc");
  $var = "abc";
} catch(MyException $e) {
  $var->action(); // @violation
}

$var = null;
try {
  throw new MyException("abc");
  $var = "abc";
} catch(Exception $e) {
  $var->action(); // @violation
}

function x() {
  $var = null;
  try {
    throw new Exception("abc");
  } catch(MyException $me) {
    $var->action(); // Safe
  }
}

function y() {
  $var = null;
  try {
    x();
    $var = "abc";
  } catch(Exception $e) {
    $var->action(); // @violation
  }
}

function g($gp) {
	if($gp > 5) {
		throw new MyException("abc");
	}
}

function f($fp) {
	if($fp > 0) {
		g($fp);
	}
}

try {
	$var = null;
	try {
		f(0);
		$var = "abc";
	} catch(MyException $e) {
		$var->action();
	}
	try {
		f(1);
		$var = "abc";
	} catch(MyException $e) {
		$var->action();
	}
} catch(MyException $e) {
	$var->action();
	var_dump($e);
	$var = "ijk";
}

$var->action();

$var2 = null;
try {
	f(10);
	$var2 = "abc";
} catch(MyException $e) {
	$var2->action(); // @violation
}
