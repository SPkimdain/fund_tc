<?php

//  ...
$filename = "a.txt";
$username = $_GET['username'];
$password = $_GET['password'];

file_put_contents($filename, $username); // Safe since the user name is not sensitive information
file_put_contents($filename, $password); // @violation
file_put_contents($filename, 'Password is ' . $password); // @violation

$password = encrypt($password);

file_put_contents($filename, $password);

function encrypt($plaintext) {
    $key = pack('H*', "bcb04b7e103a0cd8b54763051cef08bc55abe029fdebae5e1d417e2ffb2a00a3");
    $key_size =  strlen($key);
    $iv_size = mcrypt_get_iv_size(MCRYPT_RIJNDAEL_128, MCRYPT_MODE_CBC);
    $iv = mcrypt_create_iv($iv_size, MCRYPT_RAND);
    $ciphertext = mcrypt_encrypt(MCRYPT_RIJNDAEL_128, $key, $plaintext, MCRYPT_MODE_CBC, $iv);
    return $ciphertext;
}
