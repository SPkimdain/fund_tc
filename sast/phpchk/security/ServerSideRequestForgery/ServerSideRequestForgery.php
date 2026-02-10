<?php
    function violation() {
        $url = $_GET["url"];
        $resp = file_get_contents($url);            // @violation
    }

    function good() {
        $whitelist = array(
            "https://www.example.com"
        );
        $url = $_GET["url"];
        if (in_array($url, $whitelist)) {
            $resp = file_get_contents($url);        // good
            // ...
        }
    }
?>