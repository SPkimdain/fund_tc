<?php
function getRow($userName) {
  $query = "SELECT * FROM users WHERE user=" . $userName;
  $result = mysql_query($query);
  $row = mysql_fetch_array($result);
  return $row;
}

$query = "SELECT * FROM users WHERE user=". $_GET['username'];
mysql_query($query); // @violation

$query = "SELECT * FROM users WHERE user='{$_POST['username']}' AND password='{$_POST['password']}'";
mysql_query($query); // @violation

$row = getRow($_GET['username']); // @violation

$product_name        = $_POST['product_name'];
$product_description = $_POST['product_description'];

$query = sprintf("INSERT INTO products (
                 `name`, `description`, `user_id`)
                  VALUES ('%s', '%s', %d)",
                  mysql_real_escape_string($product_name, $link),
                  mysql_real_escape_string($product_description, $link),
                  mysql_real_escape_string($_POST['user_id']));
mysql_query($query, $link);
