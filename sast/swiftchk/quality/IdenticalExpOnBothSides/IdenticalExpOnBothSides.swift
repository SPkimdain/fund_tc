import UIKit

//IdenticalExpOnBothSides_test_cases

if (a == b) && (c == d){
        doX()
}

if (a == b) && (a == b){ //@violation
    doX()
}

if a == a { //@violation
    doZ()
}

if a == b && a == b {
    doX()
}

var i = 1 << 1;
var j = a << a; //@violation

var j = 5 / 5 //@false-violation
var k = 5 - 5 //@violation


if  a != a  { //@violation
    doY()
}

if a == b || a == b {
    doW()
}


// InfixOpsEndWithEqualUpLeft test cases

func **= () -> Int {
    return 1
}

func **= (p1:Int, p2:Int) -> Int {
    return p1 ** p2
}
func => (p1:Int, p2:Int) -> Int {
    return p1 ++ p1 ** p2
}

var myNumber: Float = 0.3 + 0.6 //Compliant
var myInt: Int = 4 //Compliant
if myNumber == 0.9 { //Compliant
    // ...
}

var myNumber: Float = 0.3 + 0.6 //Compliant
var myInt: Int = 4 //Compliant

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
