<?
// include test
include 'HttpTransportGetHeader.php';

$httpGet = Zend_Http_Client::GET;
$tmp = $httpGet;
getClient()->request($httpGet); // @violation
getClient()->request(Zend_Http_Client::POST);
$var = getClient();
$var2 = $var;
$var2->request($httpGet); // @violation

function testFunction() {
	$obj = getClient();
	$obj->request(Zend_Http_Client::GET); // @violation
}
?>
