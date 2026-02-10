<?
  try {
    doSomething();
  } catch (Exception $e) { // @violation

  }

  try {
    doSomething();
  } catch (Exception $e) { // Safe
    echo 'Caught exception: ', $e->getMessage(), "\n";
  }

  try {
    doSomething();
  } catch (Exception $e) {
    try {
      doExceptionHandling();
    } catch (NestedException $ne) { // @violation

    }
  } finally {
    doFinal();
  }

  if(false) {
    try {
      doSomething();
    } catch (Exception $e) { // @violation

    }
  }
