<?php
  // $ds is a valid link identifier for a directory server


  $dn = "o=My Company, c=US";
  $filter = $_GET["filter"];
  $justthese = array("ou", "sn", "givenname", "mail");

  $sr=ldap_search($ds, $dn, $filter, $justthese); // @violation

  $info = ldap_get_entries($ds, $sr);
  echo $info["count"]." entries returned\n";

  print_r($result);
