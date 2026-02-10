<?php

//  ...
$username = $_GET['username'];
$password = $_GET['password'];

$query = "SELECT * FROM users WHERE user=" . $username . " AND password=" . $password;
mysql_query($query); // @violation

$userQuery = "SELECT * FROM users WHERE user=" . $username;
mysql_query($userQuery); // Safe since the password has not been used

if(strlen($password) > 9) { // Length checking
  $filtered = "SELECT * FROM users WHERE user=" . $username . " AND password=" . $password;
   mysql_query($filtered); // Safe
}
