while((x = getX()) == 3) { // @violation
}

var x = 2;
// Bad


function getX() {
  return 3;
}

if ((x = getX()) == 3) {  // @violation
   alert('3!');
}

for( x=1; (x = getX()) == 3; x++) {} // @violation

className = className.toString().strip();