<?php

function danger() {
  $account = new BankAccount();
  // Do something
  sendAccount($account); // @violation
}

function safe() {
  $newUserName = $_GET['username'];
  $userName = $_SESSION['username']; // Get the user name from the session
  if($cond) {
    if(!strcmp($newUserName, $userName)) {
      $account = new BankAccount();
      // Do something
      sendAccount($account);
    }
  }
}

function safe2() {
  $newUserName = $_GET['username'];
  $userName = $_SESSION['username']; // Get the user name from the session
  if($cond) {
    $isAuthenticated = !strcmp($newUserName, $userName);
    if($isAuthenticated) {
      $account = new BankAccount();
      // Do something
      sendAccount($account);
    }
  }
}
