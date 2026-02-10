<?php

function danger() {
  $setRequestException = null;
  try {
    $this->_setRequest($request);
  } catch (Zend_Soap_Server_Exception $e) {
    $setRequestException = $e;
  }

  $soap = $this->_getSoap();

  ob_start();
  // Send SOAP fault message if we've catched exception
  $soap->fault("Sender", $setRequestException->getMessage()); // @violation
}

function safe() {
  $setRequestException = null;
  try {
    $this->_setRequest($request);
  } catch (Zend_Soap_Server_Exception $e) {
    $setRequestException = $e;
  }

  $soap = $this->_getSoap();

  ob_start();
  if($setRequestException instanceof Exception) {
    // Send SOAP fault message if we've catched exception
    $soap->fault("Sender", $setRequestException->getMessage());
  } else {
    try {
      $soap->handle($this->_request);
    } catch (Exception $e) {
      $fault = $this->fault($e);
      $soap->fault($fault->faultcode, $fault->faultstring);
    }
  }
}
