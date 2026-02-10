<?php
include 'XssHeader.php';

$var = $_GET['id'];
$var2 = htmlspecialchars($var);
echo $var; // @violation
$var = "header" . $var . "temp";
echo $var; // @violation
echo $var . $var2; // @violation

$getVar = getId();
$postVar = postId();

echo $getVar; // @violation
echo $postVar; // @violation
echo $postVar."temp"; // @violation

if(is_null($getVar)) {
  $getVar = "0".$postVar;
} else {
  $getVar = $getVar.$postVar;
}

echo $getVar."temp"; // @violation

$lazyVar = "";
$count = 0;
if($count >= 0) {
  if($count >= 10) {
    $lazyVar = "dummy";
  } else if($count < 5) {
    $lazyVar = $getVar;
  }
  echo $lazyVar; // @violation
}
if($count > 10) {
  echo $lazyVar; // Not an error: cannot be reached
}
$nullVar = $_GET['id'];
if($nullVar == null) {
	echo $nullVar; // Not an error: lazyVar is null
} else {
	echo $nullVar; // @violation
}

?>
<html>
<?= $var ?> // @violation
</html>
<?= $getVar . $var2 ?> // @violation

<?php
function from() {
	pass($_GET['id']); // @violation
	pass("nothing");
}

function pass($var) {
	echo to($var);
}

function to($var) {
	echo $var;
}

function b3() {
	$var = 3;
	return a1($var);
}

function c1($var) {
	$new = $var;
	if($var > 0) {
		$new = "nothing";
	}
	return b1($new) + a1("nothing");
}

function b1($var) {
	return a1($var);
}

function a1($var) {
	echo $var;
}

function a3($var, $var2, $var3) {
	echo $_GET['id']; // @violation
}

function a2($var, $var2) {
	echo $var.$var2;
}

function b2($var, $var2) {
	$return = "";
	if($var > 0) {
		$return .= a2($var, $_GET['id']); // @violation
	} else {
		$return .= a2($var, "nothing");
	}
	return $return;
}

$con = mysql_connect($server, $user, $password);
// ...
$result = mysql_query("select * from emp where id=" + eid);
echo $result; // @violation
$row = mysql_fetch_array($result);
echo $row; // @violation
echo 'Employee name: ', mysql_result($row, 0, 'name'); // @violation
