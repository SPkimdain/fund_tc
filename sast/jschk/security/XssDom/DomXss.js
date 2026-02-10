var param = document.URL;
document.write(param.indexOf(1));   //@violation

function gf() {
    return document.URL;
}

function g() {
    return document;
}

function k(v, cond) {
    if(cond == 0) {
        return v.URL;
    } else {
        return "";
    }
}

function f(v) {
    document.write("Hello " + v + "!");
}

function a() {
    var k2 = k(g(), 1);
    f(k2);  //@violation
}


document.write(document.URL.indexOf(1));   //@violation



//---------------TEST CASE 01------------- // PASS
var param = location.hash.split("#")[1];
document.write("Hello " + param + "!");  // @violation

//---------------TEST CASE 01------------- // PASS
var param = location.hash.split("#")[1];
alert("Hello " + param + "!");  // @violation

//---------------TEST CASE 03------------ // NO PASS
function timedMsg03(callback03){
    if(callback03){
        var t=setTimeout(callback03);  // No @violation
        return 0;
    }
}
function fire03(){
    var call03 = location.hash.split("#");
    var check03=timedMsg03;
    check03(call03);  // @violation
}


//---------------TEST CASE 06-------------  // PASS
function go(){
    if (document.location.hash.split("#")[1]){
        document.location.replace(document.location.hash.split("#")[1]);  // @violation
    }
}


//---------------TEST CASE 11-------------  // PASS
var doc=document;
var loc=location;
var url=loc.href;
eval(url);               // @violation

//---------------TEST CASE 23-------------  // PASS
yahoo=location.href;
function run(disco){
    eval(disco);
}
run(yahoo);  // @violation

//---------------TEST CASE 24------------  // PASS
yahoo24=location.href;
function run24(disco24){
  eval(disco24);
}
x24=run24;
z24=x24;
z24(yahoo24);   // @violation


//---------------TEST CASE 35-------------   //  PASSED
var url=location.hash.split('#')[1];
(function (disco){          //@violation
    eval(disco);
}(url));


//---------------TEST CASE 39-1-------------  // PASSED
function extract_location(obj) {
 return obj.location;
}
function extract_hash(obj) {
 return obj.hash;
}
var c = extract_hash(extract_location(document));
document.write(c)  //@violation

//---------------TEST CASE 39 - 2-------------  // PASSED
function extract_location(obj) {
 return obj.location;
}
function extract_hash(obj) {
 return obj.hash;
}
document.write((function () {  //@violation
 return extract_hash(extract_location(document));
})());

//---------------TEST CASE 41------------- // PASSED
var escaped = encodeURIComponent(document.location.hash);
document.write(escaped);   // <--- SHOULD NOT ALARM

//---------------TEST CASE 42------------- // PASSED
var escaped = encodeURIComponent(document.location.hash);

document.write(decodeURIComponent(escaped));  //@violation <---- SHOULD BE RED

//---------------TEST CASE 44------------- // PASS
function myfoo() {
 return extract_hash(extract_location(document));
}
function extract_location(obj) {
 return obj.location;
}
function extract_hash(obj) {
 return obj.hash;
}
document.write(myfoo());  //@violation

//---------------TEST CASE 46------------- // PASS
function myfoo() {
 var x = document.location.hash + '';
 return (function () {
   return x;
 })();
}
eval(myfoo());; //@violation

//---------------TEST CASE 47-------------  // PASSED
YUI({
 filter: "raw",
 combine: false
}).use("console", "escape", "node", function (Y) {
 var ln = Y.one("#last_name")
 var last_name = Y.Escape.html(document.location.hash);
 console.log("Last Name:" + last_name);
 ln.setHTML(last_name);
});

//---------------TEST CASE 48------------- // PASS
var a = location.hash.split('#')[1]
b = a;
b = "1";
eval(b); // NO violation

//---------------TEST CASE 53------------- // PASS
var asia = {
    europe: eval
}
asia.europe("location.hash.split('#')[1]"); // ← SHOULD NOT BE RED, string
asia.europe(location.hash.split('#')[1]); // @violation (eval)

//---------------TEST CASE 54------------- // PASS
var asia = {
    europe: eval
}
var xy=asia.europe;
pqr=xy;
pqr("location.hash.split('#')[1]"); // ← SHOULD NOT BE RED, string
asia.europe(location.hash.split('#')[1]); // @violation (eval)

//---------------TEST CASE 54 -2 ------------- // PASS
var asia = {
    europe: { c : eval }
}
asia.europe.c("location.hash.split('#')[1]"); // ← SHOULD NOT BE RED, string
asia.europe.c(location.hash.split('#')[1]); // @violation (eval)



//---------------TEST CASE 57-------------  ING IN NEW REPORT
apple = {
  url: location.hash.split('#')[1]
};
banana = apple.url;
carrot = {
  eclair: 1
};
dodge=carrot;
dodge.eclair=banana;
eval(dodge.eclair); // @violation

//---------------TEST CASE 59-------------
var escaped = encodeURIComponent(document.location.hash);
document.write(decodeURIComponent(decodeURIComponent(escaped))); // @violation

//---------------TEST CASE 60-------------  S
function myfoo() {
 var x = document.location.hash + ''; // ← SHOULD BE ORANGE
 return (function () {
   return x;
 })();
}
document.write(myfoo());  // @violation


//---------------TEST CASE 61-------------
function myfoo() {
 var x = document.location.hash + '';
 return (function () {
   return x;
 })();
}
myfoo = alert; // ← SHOULD NOT BE YELLOW
document.write(myfoo()); // ← SHOULD NOT BE RED

//---------------TEST CASE 62-------------  S IN NEW REPORT
function myfoo() {
 return document.location.hash.split('#')[1]
}
document.write(myfoo()); // @violation

//---------------TEST CASE 63-------------
function myfoo() {
 return document.location.hash.split('#')[1]
}
myfoo = alert;
document.write(myfoo());  // <---- SHOULD NOT BE RED


//---------TEST CASE 67----------
var abc = location.hash.split('#')[1];
eval('abc+123'); // ← SHOULD NOT BE RED


//---------------TEST CASE 07-------------  // NO PASS
var param = document.location.hash.split("#")[1];
if (param){
    var d = document.createElement('div');
    d.innerHTML = param;            // @violation (Assigning)
    if (document.body != null){
        document.body.appendChild(d);
    }
}

//---------------TEST CASE 10 -------------  // NO PASS
param = location.hash.split("#")[1];
node = document.getElementById('mydiv');
node.innerHTML=param;                        //@violation (Assigning)


//---------------TEST CASE 17-------------  // NO PASS
function xyz(asia){
    return asia;
}
mango = location.hash.split('#')[1]
div.innerHTML=xyz(mango);  //@violation (Assigning)
eval(xyz(mango));           // @violation


//---------------TEST CASE 18------------- // NO PASS
function xyz(asia){
    return asia;
}
mango = location.hash.split('#')[1]
yy = xyz;  // <---- SHOULD BE YELLOW
div.innerHTML=yy(mango);  //@violation (Assigning)
eval(yy(mango));  //@violation

//---------------TEST CASE 19-------------  // NO PASS
function xyzz(abc,asia){
    return asia;
}
mango = location.hash.split('#')[1]
div.innerHTML=xyzz("123",mango);  //@violation (Assigning)
eval(xyzz(13, mango));  // @violation


//---------------TEST CASE 20-------------  // NO PASS
function xyzzz(abc,asia){
    return asia;
}
mango = location.hash.split('#')[1]
var yy = xyzzz;
div.innerHTML=yy("123",mango);  //@violation (Assigning)
eval(yy("123",mango));   //@violation


// ---------------TEST CASE 43------------- // NO PASSED
var escaped = encodeURIComponent(document.location.hash);
div.innerHTML = decodeURIComponent(escaped);  //@violation (assigning)

// ---------------TEST CASE 45-------------  // PASSED
function myfoo() {
 return extract_hash(extract_location(document));
}
function extract_location(obj) {
 return obj.location;
}
function extract_hash(obj) {
 return obj.hash;
}
b = myfoo();
div.innerHTML = b; //@violation (assigning)

//---------------TEST CASE 46------------- // PASSED
function myfoo() {
 var x = document.location.hash + '';
 return (function () {
   return x;
 })();
}

div.innerHTML = myfoo(); //@violation (assigning)


//---------------TEST CASE 49-------------
function simple() {
 var loc=location.hash.split('#')[1]
}
var loc=location.hash.split('#')[1]
div.innerHTML=loc; //@violation (assigning)

//---------------TEST CASE 52-------------
function xyz(asia){
 return asia;
}
mango = location.hash.split('#')[1]
div.innerHTML=xyz(mango);  //@violation (assigning)
asia = '12';
eval(asia); // <---- SHOULD NOT BE RED

//---------------TEST CASE 58------------- KNOWN FALSE POSITIVE
var test = {
innerHTML: 'hello'
};
test.innerHTML = location.href; //@violation


//---------------TEST CASE 59 -2 -------------
var escaped = encodeURIComponent(document.location.hash);
div.innerHTML = decodeURIComponent(decodeURIComponent(escaped));  //@violation // <--- SHOULD BE RED



































