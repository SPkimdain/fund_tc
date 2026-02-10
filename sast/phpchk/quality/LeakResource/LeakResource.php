<?php // @violation
$myFile = fopen("webdictionary.txt", "r");
$safeFile = fopen("webdictionary.txt", "r");
// Do something
fclose($safeFile);

function danger($var) { // @violation
  $var = fopen("webdictionary.txt", "r");
}

function safe($var2) {
  $var2 = fopen("webdictionary.txt", "r");
  // Do something
  fclose($var2);
}

function returned($var3) {
  $var3 = fopen("webdictionary.txt", "r");
  // Do something
  return $var3; // Returned: safe
}

// False alarm case from CakePHP
function _readInput() {
  if (empty($_input)) {
    $fh = fopen('php://input', 'r');
    $content = stream_get_contents($fh);
    fclose($fh);
    $_input = $content;
  }
  return $_input;
}
