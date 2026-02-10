function Test2() {
   var x = 1;
   a();
   throw new err();
   function a() {}
}

// Ok
function foo() {
   return 1;
}
// Bad
function bar() {
   var x = 1;
   return x;
   x = 2;  // @violation
}

// Bad
function Test2() {
   var x = 1;
   throw new err();
   x = 2;  // @violation
}



function Test3() {
    var a = 2;
    var c = 3;
    for(var i=0; i<10; i++) {
        if( i == 0) {
            continue;
            c = 4; //@violation
        }
    }
}

function Test4() {
    var a = 3;
    var d = a;
    var e = 22;
    for(var i=0; i<10; i++) {
        if( i == 0) {
            continue;
            c = 4; //@violation
        } else if ( i == 2) {
            break;
            e = 21; //@violation
        }
    }
}

