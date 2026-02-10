function violation1(){
    var violationRegex = /^([a-zA-Z0-9])(([\-.]|[_]+)?([a-zA-Z0-9]+))*(@){1}[a-z0-9]+[.]{1}(\([a-z]{2,3})|([a-z]{2,3}[.]{1}[a-z]{2,3}))$/;//@violation
}

function violation2(){
    const regex1 = /\w+/; //@violation
    const regex2 = new RegExp('\\w+'); //@violation
    var test;
    test = /test/; //@violation

    console.log(regex1);
    // expected output: /\w+/

    console.log(regex2);
    // expected output: /\w+/

    console.log(regex1 === regex2);
    // expected output: false
}

function violation3(){
    var saferegex = require('safe-regex');
    var goodRegex = /^([a-zA-Z0-9])(([\-.]|[_]+)?([a-zA-Z0-9]+))*(@){1}[a-z0-9]+[.]{1}(\([a-z]{2,3})|([a-z]{2,3}[.]{1}[a-z]{2,3}))$/;
    var illegalRegex = /^([a-zA-Z0-9])(([\-.]|[_]+)?([a-zA-Z0-9]+))*(@){1}[a-z0-9]+[.]{1}(\([a-z]{2,3})|([a-z]{2,3}[.]{1}[a-z]{2,3}))$/;//@violation
    var result = saferegex(goodRegex);

    if(result == "true") console.log("True");
    else console.log("False");
}

function good(){
    var saferegex = require('safe-regex');
    var safeReg = require('safe-regex');
    var regex1 = new RegExp('\\w+'); //@violation
    var regex2 = new RegExp('\\w+');
    var emailRegex = /^([a-zA-Z0-9])(([\-.]|[_]+)?([a-zA-Z0-9]+))*(@){1}[a-z0-9]+[.]{1}(\([a-z]{2,3})|([a-z]{2,3}[.]{1}[a-z]{2,3}))$/;
    var testRegex = /sadf/; //@violation
    var testRegex2 = /^([a-zA-Z0-9])/;
    var testR = /sss/;
    var ViolationReg =/violation/; //@violation
    var result = saferegex(emailRegex);
    var result2 = saferegex(testRegex2);
    var testReg = safeReg(testR);
    var safeReg2 = safeReg(regex2);
    var safeReg3 = safeReg(/isSafe/);

    if(result == "true") console.log("True");
    else console.log("False");
}