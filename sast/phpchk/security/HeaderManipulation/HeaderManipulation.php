<?php
  $id = $_GET["id"];

  //  ...

  header("Location: http://www.host.com/election.php?poll_id=" . $id); // @violation
