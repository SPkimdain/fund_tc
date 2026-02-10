<?php
function danger($var) { // @violation
  $var = fopen("webdictionary.txt", "r");
  if($var == null) {
    return 0;
  }
}
