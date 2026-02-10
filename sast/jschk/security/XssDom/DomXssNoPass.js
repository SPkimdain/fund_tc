//Total  22

//---------------TEST CASE 02------------- //  NO PASS
function timedMsg(callback){
    if(callback){
        var t=setTimeout(eval('callback'),3000); // No @violation
        return 0;
    }
}
function fire(){
    var call = location.hash.split("#");
    timedMsg(call);
}
fire();

//---------------TEST CASE 04------------  // NO PASS
function timedMsg(abc,callback){
    if(callback){
        var t=setTimeout(eval('callback'),3000);  // No @violation
        return 0;
    }
}
function fire(){
    var call = location.hash.split("#")[1];
    timedMsg(12,"call");
}
fire();

//---------------TEST CASE 05------------  // NO PASS
function timedMsg(abc,callback){
    if(callback){
        var t=setTimeout(eval('callback'),3000);  // Non @violation
        return 0;
    }
}
function fire(){
    var call = location.hash.split("#")[1];
    var check=timedMsg;
    check("123",call);
}
fire();

//---------------TEST CASE 08-------------  // PASS
var redir = location.hash.split("#")[1];
x = document.getElementById('anchor');
x.setAttribute('href',redir);  // No @violation

//---------------TEST CASE 09-------------  // PASS
function reload() {
    var redir = location.hash.split("#")[1];
    if (redir){
        x = document.getElementsByTagName('iframe');
        x[0].setAttribute('src',redir);  // No @violation
    }
}

//---------------TEST CASE 13-------------  // NO PASS
var obj = {
    url: location.hash.split('#')[1],
    fantasy: function() {
        return this.url;
    }
};
eval(obj.fantasy());   // Non @violation (this)

//---------------TEST CASE 15-------------  // NO PASSED
var obj = {
    url: location.hash.split('#')[1],
    fruit: null
};
function loc() {
    return this.url;
}
obj.fruit = loc;
eval(obj.fruit());
div.innerHTML=obj.fruit();

//---------------TEST CASE 16-------------  // NO PASS
var oracle = {
    eagle: eval
    };
var bond=location;
oracle.eagle(bond);

//---------------TEST CASE 25-------------  // NO PASS
eval_alias=eval;
loc=location.hash.split('#')[1];
eval_alias(loc);  // No @violation (eval)

//---------------TEST CASE 30-------------  // NO PASS
quora = {
    zebra: function (apple) {
           return this.yahoo(apple);  // This
    },
    yahoo: eval
};
quora.zebra(location.hash.split('#')[1]); // No @violation (this)

//---------------TEST CASE 31------------- // No PASSED
quora = {
    zebra: function (apple) {
         this.yahoo=apple;   // this & assign
    },
    yahoo: div.innerHTML
};
quora.zebra(location.hash);   // No @violation (assign)

//---------------TEST CASE 32------------  // NO PASSED
quora = {
       zebra: function (apple) {
         this.yahoo(apple); // this
       },
       yahoo: eval
};
x=quora.zebra;
y=x;
y(location.hash); // No @violation (this)

//---------------TEST CASE 33------------  // NO PASSED
quora = {
    zebra: "text",
    yahoo: function () {
         this.benz=this.zebra;  // this & assign
    },
    benz: div.innerHTML
};
quora.zebra=location.hash.split('#')[1];
quora.yahoo();


//---------------TEST CASE 34------------  //  NO PASSED
quora = {
    zebra: "text",
    yahoo: function () {
         return this.benz=this.zebra;   // this
    },
    benz: div.innerHTML
};
quora.zebra=location.hash.split('#')[1];
quora.yahoo();

//---------------TEST CASE 36-------------  // NO PASS
function template() { }
template.prototype = new Object;
template.prototype.exec = eval;
template.prototype.param = location.hash.split('#')[1];   // prototype
function clone() { }
clone.prototype = new template;
var xy = new clone();
xy.exec(xy.param);          // No @violation (prototype);

//---------------TEST CASE 37-------------   // NO PASS
function template() { }
template.prototype = new Object;
template.prototype.html = div.innerHTML;
template.prototype.param = location.hash.split('#')[1];
function clone() { }
clone.prototype = new template;
var xy = new clone();
xy.html = xy.param;   // No @violation (prototype & assigning)



//---------------TEST CASE 39 - 3-------------  // NO PASSED
function extract_location(obj) {
 return obj['location']; // Named Access
}
function extract_hash(obj) {
 return obj['hash'];  // Named Access
}
(function () {
 return extract_hash(extract_location(document));  // No @violation (function closure return)
})();

//---------------TEST CASE 40-------------   // NO PASS
var s_rev = ')hsah.noitacol.tnemucod(etirw.tnemucod';
var s_script = s_rev.split("").reverse().join(""); //reverse
eval(s_script);

//---------------TEST CASE 50------------- // NO PASS
var obj = {
    url: location.hash.split('#')[1],
    fantasy: function() {
        return this.url;   // this
    }
};
eval(obj.fantasy);  // no @violation (fantasy is function)
eval(obj.fantasy()); // assigining

//---------------TEST CASE 51------------- // NO PASS
var obj = {
          url: location.hash.split('#')[1],
          fruit: null
         };
function loc() {
    return this.url;   // this
}
obj.fruit = loc;  // ← Should be yellow
eval(obj.fruit);  // <----- SHOULD NOT BE RED
div.innerHTML=obj.fruit(); // <----- SHOULD BE RED



//---------------TEST CASE 56------------   - INCORRECT COLORING
quora = {
       zebra: function (apple) {
         return this.yahoo(apple);  // this
       },
       yahoo: eval
};
x=quora.yahoo; // ← SHOULD BE PINK
y=x; // ← SHOULD BE PINK
y(location.hash); // ← SHOULD BE RED


//---------------TEST CASE 64------------- // REVERSE
var s_rev = ')hsah.noitacol.tnemucod(etirw.tnemucod';
var s_script = s_rev.split("").reverse().join("");
b = Y.Escape.html(s_script);
eval(b); // ← SHOULD BE RED














