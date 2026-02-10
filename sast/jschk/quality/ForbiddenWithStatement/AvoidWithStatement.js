function doSomething(value, obj) {
    with (obj) {  // @violation
        value = "which scope is this?";
        console.log(value);
    }
}

with (document.getElementById("myDiv").style) {  // @violation
    background = "yellow";
    color = "red";
    border = "1px solid black";
}

var r = 10, a, x, y;
with (Math) {  // @violation
    a = PI * r * r;
    x = r * cos(PI);
    y = r * sin(PI / 2);
}


var user = {
    name: "unikys",
    homepage: "unikys.tistory.com",
    language: "Korean"
}
with (user) {  // @violation
    console.log(name === "unikys");
    console.log(homepage === "unikys.tistory.com");
    console.log(language === "Korean");
    language = "javascript";
}
console.log(user.language === "javascript");

with (mylibrary) {  // @violation
    with (window) {  // @violation
        console.log("do something while the global scope has priority");
    }
}

function toString(string) {
    console.log(string);
}
with ({test: "hello"}) {  // @violation
    with (window) {  // @violation
        toString(test);
    }
}