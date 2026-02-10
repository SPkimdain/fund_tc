<?
function getClient() {
    $client = new Zend_Http_Client('http://www.test.com/index.php');
    // Do something ...
    if($var > 10) {
        return $client;
    } else {
        return 0;
    }
}
?>
