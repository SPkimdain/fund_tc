<?
$var = null;

echo $var->getString(); // @violation

function safe($ps) {
  if($ps != null) {
    $ps->getString();
  }
}

function danger($pd) {
  $pd->getString();
}

function safe2($ps2) {
  if($ps2 != null) {
    danger($ps2);
  } else {
    safe($ps2);
  }
}

function danger2($pd2) {
  if($pd2 !== null) {
    safe($pd2);
  } else {
    danger($pd2); // @violation
  }
}

function safe3() {
  $var2 = null;
  if($var2 === null) {
    safe($var2);
  } else {
    $var2->getString();
  }
}

function act($pa) {
  safe2($pa);
  danger2($pa);
}

function g($param) {
  $param->getString();
}

function f($base) {
  $base->getString();
  if($base === null) {
    $base->getString(); // @violation
  }
  $base->getString();
  if($base != null) {
    $base->getString();
  }
  g(null); // @violation
  act(null); // @violation
}
