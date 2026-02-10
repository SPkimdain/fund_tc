<?php
$myFile = fopen("webdictionary.txt", "r");
fwrite($myFile, "hello");
fclose($myFile);

$var = fread($myFile, 5); // @violation
fwrite($myFile, "hello"); // @violation
fclose($myFile);
