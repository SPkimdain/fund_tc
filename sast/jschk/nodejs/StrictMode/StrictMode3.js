var v = "Hi!  I'm a strict mode script!";
var test = "use strict";
"test mode";
"use strict"; //@violation

const violationModule = require('StrictMode6.js');
const goodModule = require('StrictMode5.js');

violationModule.printHelloWorld();

goodModule.printHelloWorld();

function violation()//@violation
{
    "use strict";
    var test;
}

var anonymousTest = function() { //@violation
    var test = "use strict";
    "use strict" //@violation
}

function overloadTest() {   //@violation
    var test = "use strict";
    "use strict" //@violation
    console.log("use strict");
}

function overloadTest(i) {
    var test = "Hi! I'm a function strict mode0";
    var test = "use strict";

    console.log("use strict");
}

function overloadTest(i, j) { //@violation
    console.log("use strict");
    "use strict"; //@violation
    var test = "Hi! I'm a function strict mode0";
}