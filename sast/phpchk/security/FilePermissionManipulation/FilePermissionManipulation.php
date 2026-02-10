<?php

// ...
$rName = $_GET['publicReport'];
chmod("/home/public_html/" . $rName, "0755"); // @violation

$filename = "/home/secure.txt";
$mask = $CONFIG_TXT['perms'];
chmod($filename, $mask); // @violation
