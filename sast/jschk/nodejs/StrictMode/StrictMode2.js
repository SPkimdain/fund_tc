'use strict';
"test";

var v = "Hi!  I'm a strict mode script!";
var temp = "use strict";

function nullTest(){
}

var anonymousTest = function(){
}

function overloadTest(){
    var test = "Hi! I'm a function strict mode0";
}

function overloadTest(i){
    var test = "Hi! I'm a function strict mode0";
    var test = "use strict";

    console.log("use strict");
}

function overloadTest(i, j){
    var test = "Hi! I'm a function strict mode0";
}