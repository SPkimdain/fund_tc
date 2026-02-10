//InfixOpsEndWithEqualUpLeft_test_cases

func **= () -> Int {   // Noncompliant. Change operator name or update value of first parameter
    return 1
}

func **= (p1:Int, p2:Int) -> Int {   // Noncompliant. Change operator name or update value of first parameter
    return p1 ** p2
}

func => (p1:Int, p2:Int) -> Int {  // Compliant; doesn't end with '='
    return p1 ++ p1 ** p2
}

//IdenticalExpOnBothSides_test_cases

if (a == b) && (a == b)&& (a == b){ //not compliant
        doX()
}

if a == b && a == b { // compliant
doX()
}

var i = 1 << 1; // Compliant
var j = a << a; // Noncompliant

var j = 5 / 5 //always 1, Noncompliant
var k = 5 - 5 //always 0, Noncompliant


if  a != a  { // always false, Noncompliant
doY()
}

if a == b || a == b { // compliant
doW()
}

var myNumber: Float = 0.3 + 0.6
var myInt: Int = 4
if myNumber == 0.9 { //@violation
    // ...
}

if myNumber <= 0.9 && myNumber >= 0.9 { //@violation
  // ...
}

if myNumber < 0.9 || myNumber > 0.9 { //@violation
  // ...
}

if myInt > 3 { //Compliant
  // ...
}