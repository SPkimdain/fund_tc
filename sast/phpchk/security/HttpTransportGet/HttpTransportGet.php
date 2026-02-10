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
