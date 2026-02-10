
const printHelloWorld = () =>{
    console.log('hello World');
}

function notExport(){
    // ...
}

var PI = Math.PI;

module.exports = printHelloWorld;

export default function cube1(x){ //@violation
    'use strict';
    return x * x * x;
}

export default function cube2(x,y){ //@violation
    var temp;
    'use strict'; //@violation
    return x * y * x;
}

function myStrictFunction(){
    // ...
}

export default myStrictFunction;