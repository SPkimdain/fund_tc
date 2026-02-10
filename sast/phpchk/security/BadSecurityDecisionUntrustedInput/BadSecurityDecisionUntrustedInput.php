<?php
  $key = "role";

  if(!strcmp("admin", $_COOKIE[$key])) { // @violation
    echo "Admin role!";
  } else if(!strcmp("user", $_COOKIE[$key])) { // @violation
    echo "User role!";
  } else if(!strcmp("admin", $_SESSION[$key])) {
    echo "Session admin role!";
  }

  $tmpCookie = $_COOKIE;
  $tmpCookie2 = $tmpCookie;
  if(!strcmp("admin", $tmpCookie2[$key])) { // @violation
    echo "Admin role!";
  } else if(!strcmp("admin", $tmpCookie2["anotherKey"][$key])) {
    echo "Admin role for anotherKey!";
  }
