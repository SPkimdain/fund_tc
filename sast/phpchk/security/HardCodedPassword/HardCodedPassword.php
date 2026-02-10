<?php
  $link = mysql_connect('localhost', 'mysql_user', '12345678'); // @violation
  if (!$link) {
      die('Could not connect: ' . mysql_error());
  }
  echo 'Connected successfully';
  mysql_close($link);

  function connectDangerous() {
    $pwd = '12345678';
    $link = mysql_connect('localhost', 'mysql_user', $pwd); // @violation
    if(false) {
      // Should be caught even though the path is infeasible
      $link = mysql_connect('localhost', 'mysql_user', $pwd); // @violation
    }
    if (!$link) {
        die('Could not connect: ' . mysql_error());
    }
    echo 'Connected successfully';
    mysql_close($link);
  }

  function connectInfeasible() {
    // How about this?
    $pwd = loadPwd();
    if(false) {
      $pwd = '12345678'; // Cannot be reached
    }
    $link = mysql_connect('localhost', 'mysql_user', $pwd); // Safe

    // Or this can be done
    $pwd = '12345678';
    if(false) {
      $pwd = loadPwd();
    }
    $link = mysql_connect('localhost', 'mysql_user', $pwd); // @violation
  }

  function connectSafe() {
    $pwd = loadPwd();
    $link = mysql_connect('localhost', 'mysql_user', $pwd); // Safe
    if (!$link) {
        die('Could not connect: ' . mysql_error());
    }
    echo 'Connected successfully';
    mysql_close($link);
  }
