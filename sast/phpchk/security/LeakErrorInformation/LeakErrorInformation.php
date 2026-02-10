<?php
  try {
    doSomething();
  } catch (Exception $e) {
    var_dump($e->getTraceAsString()); // @violation
  }

  try {
    doSomething();
  } catch (Exception $e) {
    var_dump(debug_backtrace()); // @violation
  }

  $var = 0;
  try {
    doSomething();
  } catch (Exception $e) {
    var_dump($var); // Safe
  }

  try {
    doSomething();
  } catch (Exception $e) {
    debug_print_backtrace(); // @violation
  }

  phpinfo(); // @violation

  $sensitive = $_GET['sensitiveInfo'];

  print_r($sensitive); // @violation
  printf("%s", $sensitive); // @violation
  trigger_error($sensitive); // @violation
