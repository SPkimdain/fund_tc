//---------TEST CASE 68----------
function loadObj(){
 var cc=eval('('+aMess+')');   //@violation <- No violation (Hoisting)
 document.getElementById('mess').textContent=cc.message;
}

if(window.location.hash.indexOf('message')==-1)
  var aMess="({\"message\":\"Hello User!\"})";
else
  var aMess=location.hash.substr(window.location.hash.indexOf('message=')+8);

loadObj(); // @violation



//----------TEST CASE 66---------
document.write(l); // @violation <← SHOULD NOT BE RED (Hoistring)
var l = location.hash.split('#')[1];