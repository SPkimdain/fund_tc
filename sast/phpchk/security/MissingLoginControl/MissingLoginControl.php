<?php

function login() {
  for($i=10; $i<10; $i++) {
    // Login here ...
  }
}

function anotherLogin() {
  $i = 0;
  while($i<10) {
    // Login here ...
  }
}

function another2Login() {
  $i = 0;
  do {
    // Login here ...
  } while($i<10);
}

function another3Login() {
  for(;;) { // @violation
    // Login here ...
  }
}

function another4Login() {
  $i = 0;
  while(((true))) { // @violation
    // Login here ...
  }
}

function f1() {
  login(); // @violation
}

function f2() {
  for($i=0; $i<10; $i++) {
    login();
  }
}

function f3() {
  $i = 0;
  while($i < 10) {
    login();
    $i++;
  }
}

function f4() {
  for($i=0; true; $i++) {
    login(); // @violation
  }
}

function f5() {
  $i = 0;
  while(((true))) {
    login(); // @violation
    $i++;
  }
}

function f6() {
  do {
    login(); // @violation
  } while(true);
}
