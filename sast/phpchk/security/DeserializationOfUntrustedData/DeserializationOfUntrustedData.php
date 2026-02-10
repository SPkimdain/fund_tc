<?php
    function violation() {
        $data = $_GET["data"];
        $object = unserialize($data);       // @violation
    }

    function good() {
        $data = $_GET["data"];

        list($hash, $data) = explode('|', $data, 2);
        $hash_confirm = hash_hmac("sha256", $data, "secret-key");

        if ($hash === $hash_confirm) {      // good
          $object = unserialize($data);
        }
    }

?>