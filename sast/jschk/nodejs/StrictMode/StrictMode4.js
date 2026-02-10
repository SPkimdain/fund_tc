//"use strict";
var v = "Hi!  I'm a strict mode script!"; //@violation
var temp = "use strict";
console.log("use strict");

function violationfunc(){ //@violation
    "use strict";
    var info = "Hi! I'm a function1 strict mode";
}

function test2(){
    var info = "Hi! I'm a function2 strict mode";
}

function violationFunc3(){//@violation
    "use strict"
    var info = "Hi! I'm a function3 strict mode";
}
