<?php

$value = $_GET['value'];

// ...

$message = "Invalid value: " . $value;
error_log($message); // @violation
