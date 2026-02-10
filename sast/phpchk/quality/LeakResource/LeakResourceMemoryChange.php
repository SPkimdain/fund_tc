<?php

function open(&$p) {
  $p = fopen("webdictionary.txt", "r");
}

function close(&$p) {
  fclose($p);
}

function q1() {
  $x = 0;
	open($x);
	close($x);
}

function q2() {
  $x = 0;
	close($x);
}

function q3() { // @violation
  $x = 0;
	open($x);
}

function openCond(&$p, $q) {
  if($q > 20) {
    $p = fopen("webdictionary.txt", "r");
  }
}

function closeCond(&$p, $q) {
  if($q > 30) {
    fclose($p);
  }
}

function t1() {
  $x = 0;
  $var = 45;
  openCond($x, $var);
  closeCond($x, $var);
}

function t2() { // @violation
  $x = 0;
  $var = 25;
  openCond($x, $var);
  closeCond($x, $var);
}

function t3() {
  $x = 0;
  $var = 15;
  openCond($x, $var);
  closeCond($x, $var);
}

function t4() { // @violation
  $x = 0;
  $var = 45;
  if($var > 20) {
    openCond($x, $var);
  }
  if($var < 30) {
    openCond($x, $var);
  }
}

function t5($var) { // @violation
  $x = 0;
  if($var > 30) {
    openCond($x, $var);
  }
  if($var < 20) {
    closeCond($x, $var);
  }
}

function t5($var) {
  $x = 0;
  if($var > 50) {
    openCond($x, $var);
  }
  if($var > 40) {
    closeCond($x, $var);
  }
}
