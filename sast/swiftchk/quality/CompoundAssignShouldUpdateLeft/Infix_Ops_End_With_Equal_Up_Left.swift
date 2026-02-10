import UIKit

//IdenticalExpOnBothSides_test_cases

if (a == b) && (c == d){
        doX()
}

if (a == b) && (a == b){
    doX()
}

if a == a {
    doZ()
}

if a == b && a == b {
    doX()
}

var i = 1 << 1;
var j = a << a;

var j = 5 / 5
var k = 5 - 5


if  a != a  {
    doY()
}

if a == b || a == b {
    doW()
}


// InfixOpsEndWithEqualUpLeft test cases

func **= () -> Int {   //Compliant, this is not a case
    return 1
}

func **= (p1:Int, p2:Int) -> Int {   //@violation
    return p1 ** p2
}

func => (p1:Int, p2:Int) -> Int {  // Compliant; doesn't end with '='
    return p1 ++ p1 ** p2
}

func ***= (p1:Int, p2:Int) {  // Compliant;
    p1 = p1 *** p2
}

func ==> (p1:Int, p2:Int) -> Int {  // Compliant;
    return p1 ** p1 ** p2
}

var myNumber: Float = 0.3 + 0.6 //Compliant
var myInt: Int = 4 //Compliant

if myNumber == 0.9 { //Compliant
    // ...
}

if myNumber <= 0.9 && myNumber >= 0.9 { //Compliant
  // ...
}

if myNumber < 0.9 || myNumber > 0.9 { //Compliant
  // ...
}

while myNumber > 0 { //Compliant
 // ...
}

if myInt > 3 { //Compliant
  // ...
}