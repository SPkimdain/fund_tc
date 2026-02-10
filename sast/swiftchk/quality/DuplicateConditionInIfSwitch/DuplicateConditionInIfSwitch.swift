



/* ====================================================================
    Author: Jiho Choi

    TEST CASE 01 - 1
        : DuplicateConditionInIfSwitch.java
        if statement with/without duplicate conditions
==================================================================== */


switch someCharacter {
    case "a":
        do1();
    case "z":
        do2();
    case "k":
        do3();
    default:
        do4();
}



switch hello { //@violation
case 1:
     do1()
case 2, 3:
     do23()
case 3:
     do23()
default:
     do4()
}


// error o With an error
if a1 == a1 || b1 == b1 {
 do1()
} else if a2 == b2 { //@violation
 do2()
} else if a2 == b2 {
  do2()
}  else if b3 == a3 {
 do3()
} else {
 do4()
}



// error x
if a == a {
 do1()
} else if a2 == b2 {
 do2()
} else if b3 == a3 {
 do3()
} else {
 do4()
}

// error x
if a1 == a1 || a1 == a1  { // this line should be handled by different checker (cf. Identical condition expression checker)
 do1()
}



/* ====================================================================
    Author: Jiho Choi

    TEST CASE 01 - 2
        : DuplicateConditionInIfSwitch.java
        switch statement with/without duplicate conditions
==================================================================== */

switch someCharacter { //@violation
    case "a":
        do1();
    case "z":
        do2();
    case "z":
        do22();
    case "k":
        do3();
    default:
        do4();
}

switch someCharacter {
    case "a":
        do1();
    case "z":
        do2();
    case "k":
        do3();
    default:
        do4();
}



/* ====================================================================
    Author: Jiho Choi

    TODO :
    NOTES : sequence switch statements are causing parser error

    TEST CASE 01 - 3
        : DuplicateConditionInIfSwitch.java
        switch statement with/without duplicate conditions
==================================================================== */


switch hello { //@violation
case 1:
     do1()
case 2, 3:
     do23()
case 3:
     do23()
default:
     do4()
}

switch approximateCount {
    case 0:
        do0();
    case 1..<5:
        do2();
    case 5..<12:
        do3();
        do4();
    default:
        do5();
}

switch approximateCount { //@violation
    case 0:
        do0();
    case 1..<5:
        do2();
    case 5..<12:
        do3();
    case 5..<12:
        do4();
    default:
        do5();
}

let someCharacter: Character = "z"
switch someCharacter { //@violation
case "a":
    print("The first letter of the alphabet")
case "z":
    print("The last letter of the alphabet")
case "z":
    print("The last letter of the alphabet")
default:
    print("Some other character")
}

switch someCharacter2 { //@violation
case "a":
    print("The first letter of the alphabet")
case "z":
    print("The last letter of the alphabet")
    fallthrough
case "z":
    print("The last letter of the alphabet")
default:
    print("Some other character")
}