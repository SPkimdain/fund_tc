<?php
  $xml = simplexml_load_file("test.xml");

  $query = $_GET["query"];
  $result = $xml->xpath($query); // @violation

  print_r($result);
