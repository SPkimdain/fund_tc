<?php

  function dangerousMcrypt() {
    $string = "Some text to be encrypted";
    $secret_key = "This is my secret key";

    // Create the initialization vector for added security.
    $iv = mcrypt_create_iv(mcrypt_get_iv_size(MCRYPT_RIJNDAEL_256, MCRYPT_MODE_ECB), MCRYPT_RAND);

    // Encrypt $string
    $encrypted_string = mcrypt_encrypt(MCRYPT_RIJNDAEL_256, $secret_key, $string, MCRYPT_MODE_CBC, $iv); // @violation

    // Decrypt $string
    $decrypted_string = mcrypt_decrypt(MCRYPT_RIJNDAEL_256, $secret_key, $encrypted_string, MCRYPT_MODE_CBC, $iv); // @violation
  }

  function safeMcrypt() {
    $string = "Some text to be encrypted";
    $secret_key = generateKey();

    // Create the initialization vector for added security.
    $iv = mcrypt_create_iv(mcrypt_get_iv_size(MCRYPT_RIJNDAEL_256, MCRYPT_MODE_ECB), MCRYPT_RAND);

    // Encrypt $string
    $encrypted_string = mcrypt_encrypt(MCRYPT_RIJNDAEL_256, $secret_key, $string, MCRYPT_MODE_CBC, $iv);

    // Decrypt $string
    $decrypted_string = mcrypt_decrypt(MCRYPT_RIJNDAEL_256, $secret_key, $encrypted_string, MCRYPT_MODE_CBC, $iv);
  }

  function dangerousOpenSSL() {
    $publicKey = "file://path/to/public/key-crt.pem";
    $plaintext = "String to encrypt";

    openssl_public_encrypt($plaintext, $encrypted, $publicKey); // @violation

    echo $encrypted;   //encrypted string
  }

  function safeOpenSSL() {
    $publicKey = generateKey();
    $plaintext = "String to encrypt";

    openssl_public_encrypt($plaintext, $encrypted, $publicKey);

    echo $encrypted;   //encrypted string
  }
