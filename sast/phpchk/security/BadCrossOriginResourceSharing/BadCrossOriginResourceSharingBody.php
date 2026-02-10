<?
include 'BadCrossOriginResourceSharingHeader.php';

function getHeaderString($key, $value) {
    return $key . ": " . $value;
}

function getHeaderStringAnother($key, $value) {
    return concatenate(concatenate($key, ": "), $value);
}

header('Access-Control-Allow-Origin: *'); // @violation
header('Access-Control-Allow-Origin: ');

$key = 'Access-Control-Allow-Origin';
$value = '*';

header($key . ': ' . $value); // @violation
header(getHeaderString(pass($key), $value)); // @violation
header(getHeaderStringAnother($key, $value)); // @violation
?>
