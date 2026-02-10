

//---------------TEST CASE 12-------------  // NO PASS
function simple(){
  loc = location.hash.split('#')[1]
}
simple();
div.innerHTML=loc;          //Non @violation (function call info)

//---------------TEST CASE 13-------------  // NO PASS
var obj = {
    url: location.hash.split('#')[1],
    fantasy: function() {
        return this.url;
    }
};
div.innerHTML=obj.fantasy();  //No @violation (Assigning & THIS)


//---------------TEST CASE 26-------------  // No PASS
function apple(fruit){
    if(fruit.hasOwnProperty('innerHTML'))
       return fruit.innerHTML;
}
yahoo=document.getElementsByTagName('div')[0];
mango=apple(yahoo);
mango=location.hash.split('#')[1]  //No @violation (Assigning & no info of mango)

//---------------TEST CASE 27------------  // NO PASS
function apple(fruit){
       if(fruit.hasOwnProperty('innerHTML'))
           return fruit.innerHTML;
}
yahoo=document.getElementsByTagName('div');
mango=apple(yahoo[0]);
url = location.hash.split('#')[1]
mango = "Hello" + url + "!";  //No @violation (Assigning  no info of mango)

//---------------TEST CASE 28------------  // NO PASS
function apple(fruit,cake){
       fruit+="";
       if(cake.hasOwnProperty('innerHTML'))
           return cake.innerHTML;
}
yahoo=document.getElementsByTagName('div')[0];
berry="123";
mango=apple(berry,yahoo);
mango=location.hash.split('#')[1]   // No @violation (Assigning  no info of mango)

//---------------TEST CASE 29------------  // NO PASS
function apple(fruit){
   if(fruit.hasOwnProperty('innerHTML'))
      return fruit.innerText;
    else
      return fruit.innerHTML;
}
yahoo=document.getElementsByTagName('div')[0];
mango=apple(yahoo);
mango=location.hash.split('#')[1]  // No @violation (Assigning  no info of mango)

//---------------TEST CASE 38-------------   // IMPLEMENT - REDIFF XSS
var ck = document.cookie;
function getcookie(n) {
    var ar = n + "=";
    var al = ar.length;
    var cl = ck.length;
    var i = 0;
    while (i < cl) {
        j = i + al;
        if (ck.substring(i, j) == ar) {
            e = ck.indexOf(";", j);
            if (e == -1)
                e = ck.length;
            return unescape(ck.substring(j, e));
        }
        i = ck.indexOf(" ", i) + 1;
        if (i == 0)
            break;
    }
    return "";
}
var Rlo = "";
var Rm = "";
Rlo = getcookie("Rlo");
Rlo = unescape(Rlo).replace("+", " ");
Rm = getcookie("Rm");
if (Rlo != "" && Rm != "") {
    document.getElementById('username').innerHTML = "Hi <a href=\"http://mypage.rediff.com/profile/myprofile\">"
                            + Rlo + "</a>"; // No @violation (assigning)
}


//---------------TEST CASE 50 - 2------------- // NO PASS
var obj = {
    url: location.hash.split('#')[1],
    fantasy: function() {
        return this.url;   // this
    }
};
eval(obj.fantasy);  // no @violation (fantasy is function)
div.innerHTML = obj.fantasy(); // assigining



//---------------TEST CASE 55------------
function apple(fruit,cake){
       cake+="";   // <---- SOURCE CONVERTED TO STRING
       if(cake.hasOwnProperty('innerHTML'))
           return cake.innerHTML;  // <--- STRING HAS NO innerHTML PROPERTY
}
yahoo=document.getElementsByTagName('div')[0];
berry=123;
mango=apple(berry,yahoo);
mango=location.hash.split('#')[1]   // <---- SHOULD NOT BE RED




