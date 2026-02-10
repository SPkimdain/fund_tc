document.getElementById("demo").innerHTML = "Paragraph changed!"; // @violation

var k = document.getElementById("demo").innerHTML;
k = "changed"; // Safe

var element = document.getElementById("demo");
element.innerHTML = "changed"; // @violation

var element = document.getElementById("demo");
var name = "<img src = " + document.URL.indexOf(1) + ">";
element.innerHTML = name; // @violation
