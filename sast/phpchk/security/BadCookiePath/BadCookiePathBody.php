<?
include 'BadCookiePathHeader.php';

setcookie("cookie", $cookie, 0, "/", "test.com"); // @violation
setcookie("cookie", $cookie, 0, "/", "test.com", false); // @violation
setcookie("cookie", $cookie, 0, "/home/", "test.com", true);

$domain = "/";
setcookie("cookie", $cookie, 0, $domain, "test.com"); // @violation
$domain = "/home";
setcookie("cookie", $cookie, 0, $domain, "test.com");

session_set_cookie_params(0, "/"); // @violation
?>
