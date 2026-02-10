var str = document.URL;
var url_check = str.indexOf('name=');
var name = null;
if (url_check > -1) {
  name =  decodeURIComponent(str.substring((url_check+5), str.length));
}

$(document).ready(function(){
  if (name !== null){
    var obj = jQuery.parseJSON('{"role": "user", "name" : "' + name + '"}'); //@violation
    //...
  }
  //...
});

//Example 2

JSON.parse('{"role": "user", "name" : "' + name+ + '"}'); //@violation