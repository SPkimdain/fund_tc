<?
function getClient() {
    $client = new Zend_Http_Client('http://www.test.com/index.php');

    // Do something ...

    if($var > 10) { // Deal with the unknown value: considier all posible cases
        return $client;
    } else {
        return 0;
    }
}

function getHttpsClient() {
    $client = new Zend_Http_Client('https://www.test.com/index.php');

    // Do something ...

    if($var > 10) { // Deal with the unknown value: considier all posible cases
        return $client;
    } else {
        return 0;
    }
}
?>
