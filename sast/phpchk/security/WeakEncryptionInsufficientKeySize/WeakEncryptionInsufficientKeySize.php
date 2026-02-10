<?php

  function dangerRSA() {
    $config = array(
        "digest_alg" => "sha512",
        "private_key_bits" => 1024,
        "private_key_type" => OPENSSL_KEYTYPE_RSA,
    );

    // Create the private and public key
    $res = openssl_pkey_new($config); // @violation
  }

  function safeRSA() {
    $config = array(
        "digest_alg" => "sha512",
        "private_key_bits" => 4096,
        "private_key_type" => OPENSSL_KEYTYPE_RSA,
    );

    // Create the private and public key
    $res = openssl_pkey_new($config);
  }

  function dangerEC() {
    $config = array(
        "digest_alg" => "sha512",
        "private_key_bits" => 128,
        "private_key_type" => OPENSSL_KEYTYPE_EC,
    );

    // Create the private and public key
    $res = openssl_pkey_new($config); // @violation
  }

  function safeEC() {
    $config = array(
        "digest_alg" => "sha512",
        "private_key_bits" => 256,
        "private_key_type" => OPENSSL_KEYTYPE_EC,
    );

    // Create the private and public key
    $res = openssl_pkey_new($config);
  }

  function safeOthers() {
    $config = array(
        "digest_alg" => "sha512",
        "private_key_bits" => 256,
        "private_key_type" => OPENSSL_KEYTYPE_DH,
    );

    // Create the private and public key
    $res = openssl_pkey_new($config);
  }
