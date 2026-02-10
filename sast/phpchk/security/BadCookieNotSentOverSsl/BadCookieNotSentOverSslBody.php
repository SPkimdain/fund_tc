<?
include 'BadCookieNotSentOverSslHeader.php';

setcookie("cookie", $cookie, 0, "/", "test.com"); // @violation
setcookie("cookie", $cookie, 0, "/", "test.com", false); // @violation
setcookie("cookie", $cookie, 0, "/", "test.com", true);

$flag = false;
setcookie("cookie", $cookie, 0, "/", "test.com", $flag); // @violation
$flag = $flag | true;
setcookie("cookie", $cookie, 0, "/", "test.com", $flag);

setcookie("cookie", $cookie, 0, "/", "test.com", getFalse()); // @violation
setcookie("cookie", $cookie, 0, "/", "test.com", getTrue());
?>
