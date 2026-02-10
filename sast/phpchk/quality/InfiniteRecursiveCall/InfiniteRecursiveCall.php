<?php
  function call() {
    if($var < 0) {
      call();
    } else if($var < 5) {
      call();
    } else if(0 < -1) {
      call();
    } else {
      call();
    }
  }

  function call2() {
    call2(); // @violation
  }

  function call3() {
    return;
    call3(); // Unreachable
  }

  function call4() {
    if($var < 0) {
      call4(); // @violation
    } else {
      call4(); // @violation
    }
  }

  function call5($param) {
    if($param < 0) {
      return 2;
    }
    return call5($param-1); // Safe
  }

  function call6($param) {
    if($param < 0) {
      return call6($param+1); // @violation
    }
    return call6($param-1); // @violation
  }

  function call7() {
    call2();
    call7(); // @violation
  }

  function call8() {
    return call2();
    return call8(); // Unreachable code
  }

  function call9() {
    if($var < 0) {
      call2();
    } else {
      call9(); // Safe
    }
  }
