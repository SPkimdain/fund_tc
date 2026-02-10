<?php

  function decision() {
    $hostname = gethostname();
    $trusted = "trustme.trusty.com";
    if(!strcmp($hostname, $trusted)) { // @violation
      return 1; // true
    } else {
      return 0; // false
    }
  }
