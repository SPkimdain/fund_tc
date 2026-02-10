<?php
  require_once 'Zorba/XQueryProcessor.php';

  $xquery = new XQueryProcessor();

  $query = $_GET["query"];
  $xquery->importQuery($query);
  $xquery->setVariable('world', 'World!');
  echo $xquery->execute(); // @violation
