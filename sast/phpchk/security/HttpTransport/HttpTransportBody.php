<?
include 'HttpTransportHeader.php';

$client = new Zend_Http_Client('http://www.test.com/indx.php');
$client->request(Zend_Http_Client::POST); // @violation

$client = new Zend_Http_Client('https://www.test.com/indx.php');
$client->request(Zend_Http_Client::POST);

getClient()->request(Zend_Http_Client::POST); // @violation
$var = getClient();
$var2 = $var;
$var2->request(Zend_Http_Client::POST); // @violation

function testFunction() {
	$obj = getClient();
	$obj->request(Zend_Http_Client::GET); // @violation
}

$httpsVar = getHttpsClient();
$httpsVar->request(Zend_Http_Client::POST);
?>
