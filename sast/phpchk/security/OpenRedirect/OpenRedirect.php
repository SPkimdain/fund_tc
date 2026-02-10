<?php
  function danger() {
    $id = $_GET["id"];

    //  ...

    header("Location: http://www.host.com/election.php?poll_id=" . $id); // @violation
    header($id); // Safe

    $locHeader = "Location: ";
    $url = "http://www.host.com/election.php?poll_id=";

    header($locHeader . $url . $id); // @violation
  }

  function safe() {
    $id = $_GET["id"];

    //  ...

    $part = $whitelist[$id];
    if(isset($part)) {
      header("Location: http://www.host.com/election.php?poll_id=" . $part);
    }
    header($id); // Safe
  }
