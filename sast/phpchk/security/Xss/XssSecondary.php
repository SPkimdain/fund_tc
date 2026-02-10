<?php
include 'XssBody.php';

function e1() {
	return d1($_GET['id']); // @violation
}

function d1($var) {
	if($var > 0) {
		return c1($var . $var);
	} else {
		return c1("nothing");
	}
}

function d2() {
	c1(getId()); // @violation
}
