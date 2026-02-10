<?php
function getId() {
  return $_GET['id'];
}

function postId() {
  $var = $_POST['id'];
  if(is_null($var)) {
      return "";
  } else {
      return $var;
  }
}

$link = $_GET['link'];
?>
<a href=http://test.com/list.cgi?clientprofile=<?=urlencode($link) ?>>
  Click here
</a>
