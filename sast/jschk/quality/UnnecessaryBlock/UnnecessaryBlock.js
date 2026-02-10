if(nErrorCode !== 0) {
    trace("svcid:"+strSvcId+":"+nErrorCode + " : " + strErrorMag);
    gfnErrorHandler( nErrorCode, gfnGetMsg( strErrorMag ) );
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

