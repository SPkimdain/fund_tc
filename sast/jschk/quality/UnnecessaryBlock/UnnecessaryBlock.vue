<template>
    <div>
        <h1>UnnecessaryBlock</h1>
    </div>
</template>

<script>
if(nErrorCode <> 0) {
    trace("svcid:"+strSvcId+":"+nErrorCode + " : " + strErrorMag);
    gfnErrorHandler( nErrorCode, gfnGetMsg( strErrorMag ) );
    return;
}


if (foo) {
   // Ok
}
if (bar) {
   { //@violation
      // Bad
   }
}

for (var a = 1; a < 10; a++) {
   { //@violation
      // Bad
   }
}


</script>

<style>
  #computer {
    width: 142px;
    height: 200px;
    background-position: 0 0;
  }
</style>
