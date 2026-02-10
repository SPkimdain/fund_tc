<?php

  function dangerOpenSSL() {
    $string = 'It works ? Or not it works ?';
    $pass = '1234';
    $method = 'des';

    file_put_contents ('./file.encrypted', openssl_encrypt ($string, $method, $pass)); // @violation
  }

  function dangerOpenSSL2() {
    $string = 'It works ? Or not it works ?';
    $pass = '1234';
    $method = 'rc2';

    file_put_contents ('./file.encrypted', openssl_encrypt ($string, $method, $pass)); // @violation
  }

  function dangerOpenSSL3() {
    $string = 'It works ? Or not it works ?';
    $pass = '1234';
    $method = 'rc4';

    file_put_contents ('./file.encrypted', openssl_encrypt ($string, $method, $pass)); // @violation
  }

  function safeOpenSSL() {
    $string = 'It works ? Or not it works ?';
    $pass = '1234';
    $method = 'aes128';

    file_put_contents ('./file.encrypted', openssl_encrypt ($string, $method, $pass));
  }

  function dangerMcrypt() {
      $key = pack('H*', "bcb04b7e103a0cd8b54763051cef08bc55abe029fdebae5e1d417e2ffb2a00a3");
      $key_size =  strlen($key);
      echo "Key size: " . $key_size . "\n";
      $plaintext = "This string was AES-256 / CBC / ZeroBytePadding encrypted.";
      $iv_size = mcrypt_get_iv_size(MCRYPT_DES, MCRYPT_MODE_CBC);
      $iv = mcrypt_create_iv($iv_size, MCRYPT_RAND);
      $ciphertext = mcrypt_encrypt(MCRYPT_DES, $key, // @violation
                                   $plaintext, MCRYPT_MODE_CBC, $iv);
  }

  function dangerMcrypt2() {
      $key = pack('H*', "bcb04b7e103a0cd8b54763051cef08bc55abe029fdebae5e1d417e2ffb2a00a3");
      $key_size =  strlen($key);
      echo "Key size: " . $key_size . "\n";
      $plaintext = "This string was AES-256 / CBC / ZeroBytePadding encrypted.";
      $iv_size = mcrypt_get_iv_size(MCRYPT_RC2, MCRYPT_MODE_CBC);
      $iv = mcrypt_create_iv($iv_size, MCRYPT_RAND);
      $ciphertext = mcrypt_encrypt(MCRYPT_RC2, $key, // @violation
                                   $plaintext, MCRYPT_MODE_CBC, $iv);
  }

  function dangerMcrypt3() {
      $key = pack('H*', "bcb04b7e103a0cd8b54763051cef08bc55abe029fdebae5e1d417e2ffb2a00a3");
      $key_size =  strlen($key);
      echo "Key size: " . $key_size . "\n";
      $plaintext = "This string was AES-256 / CBC / ZeroBytePadding encrypted.";
      $iv_size = mcrypt_get_iv_size(MCRYPT_RC4, MCRYPT_MODE_CBC);
      $iv = mcrypt_create_iv($iv_size, MCRYPT_RAND);
      $ciphertext = mcrypt_encrypt(MCRYPT_RC4, $key, // @violation
                                   $plaintext, MCRYPT_MODE_CBC, $iv);
  }

  function safeMCrypt() {
      $key = pack('H*', "bcb04b7e103a0cd8b54763051cef08bc55abe029fdebae5e1d417e2ffb2a00a3");
      $key_size =  strlen($key);
      echo "Key size: " . $key_size . "\n";
      $plaintext = "This string was AES-256 / CBC / ZeroBytePadding encrypted.";
      $iv_size = mcrypt_get_iv_size(MCRYPT_RIJNDAEL_128, MCRYPT_MODE_CBC);
      $iv = mcrypt_create_iv($iv_size, MCRYPT_RAND);
      $ciphertext = mcrypt_encrypt(MCRYPT_RIJNDAEL_128, $key,
                                   $plaintext, MCRYPT_MODE_CBC, $iv);
  }
