<?php

  function sprint($arg) {
    $y = 2;
    $format2 = $_GET["format2"];
    return sprintf($format2, $arg); // @violation
  }


 function print($arg) {
    $x = 1;
    $format = $_GET["format"]; // Get the format
    printf($format, $arg); // @violation
  }


?>