<?php

function danger($var) { // @violation
  $var = fopen("webdictionary.txt", "r");
  return 0;
}
