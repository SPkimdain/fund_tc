<?php
function danger($param) {
  if($param == null) {
    $param->action(); // @violation
  }
}

function danger2($cond) {
  if($cond) {
    $var = $unknown;
    return;
  } else {
    $var = null;
  }
  $var->action(); // @violation
}



function safe($param) {
  if($param == null) {
    return; // Exit if the param is null
  }
  if($param == null) {
    $param->action(); // Safe
  }
}

funciton safe2($cond) {
  if($cond) {
    $var = null;
    return;
  } else {
    $var = $unknown;
  }
  $var->action(); // Safe
}

?>