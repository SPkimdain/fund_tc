<?php

function t(&$p, $t) {
	$p = null;
	$t = new Object();
}

function k() {
  $x = new Object();
  t($x, $x);
  $x->action(); // @violation
}

$gx = new Object();

function q() {
  global $gx;
  p();
  $gx->action(); // @violation
}

function p() {
  global $gx;
  $gx = null;
}

function t2(&$p, $q, $r) {
	if($q > 20) {
		$p = $r;
	}
}

function t1(&$a, $b, $c) {
  if($b > 10) {
    t2($a, $b, $c);
  }
}

function q1() {
	$x = new TempObject();
	t1($x, 15, null);
	$x->action();
}

function q2() {
	$x = new TempObject();
	t1($x, 25, null);
	$x->action(); // @violation
}
