<?php
  try {
    doSomething();
  } catch (Exception $e) { // @violation
    handleException();
  }

  try {
    doSomething();
  } catch (SpecifiedException $se) { // Safe
    handleException();
  }
