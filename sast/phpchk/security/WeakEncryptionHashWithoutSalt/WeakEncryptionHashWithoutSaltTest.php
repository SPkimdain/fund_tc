<?php

function dangerRSA() {

$pass = password_hash('password', PASSWORD_DEFAULT); // @violation
$pass2 = password_hash('password', PASSWORD_BCRYPT);

echo $pass;
echo $pass2;

}


?>
