<?php

$myFile = fopen("webdictionary.txt", "r");
for($i=0; $i<10; $i++) {
	fwrite($myFile, "hello"); // @violation
	fclose($myFile);
}

$myFile = fopen("webdictionary.txt", "r");
$j = 0;
while($j < 10) {
	fwrite($myFile, "hello"); // @violation
	fclose($myFile);
	$j++;
}

$myFile = fopen("webdictionary.txt", "r");
for($i=0; $i<10; $i++) {
	fwrite($myFile, "hello");
	fclose($myFile);
	break;
}

$myFile = fopen("webdictionary.txt", "r");
for($i=0; $i<10; $i++) {
	fwrite($myFile, "hello");
	fclose($myFile);
	if($i >= 0) {
	  break;
  }
}
