<?php
$rName = $_GET['reportName'];
$rFile = fopen("/usr/local/apfr/reports/" . $rName, "a+");
// ...

unlink($rFile); // @violation

// ...

$filename = $CONFIG_TXT['sub'] . ".txt";
$handle = fopen($filename, "r");
$amt = fread($handle, filesize($filename)); // @violation

// ...

$path = "/file/img";
$nfile = "file.txt";
$filename = $_FILES['filename']['name'];
$ext_name = explode('.', $filename);
$uploadfile = $_SERVER['root'] . $path . $nfile;
move_uploaded_file($_FILES['filename']['tmp_name'], $uploadfile); // @violation

$location=$_GET['thefile'];
$data = file_get_contents ($location); // @violation
