<?php
include 'knownFile.php';
include $_GET['include'];               // @violation

$data = $_GET["data"];
eval("echo $data;");                    // @violation

$str = mysql_fetch_array(mysql_query("select field tb where id=$id"));
eval($str);                             // @violation

$handle = popen("/bin/ls", "r");        // @violation
system("/home/httpd2/htdocs/a.out");    // @violation
