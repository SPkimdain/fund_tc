<?php
@extract($_GET); // @violation
@extract($_GET, EXTR_SKIP);

$var = $_GET;
@extract($var); // @violation
