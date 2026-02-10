/* ====================================================================
    Author: Jiho Choi

    TEST CASE 02 - 1
        : JumpShouldBeConditional.java
        jump statement(= control statement + return statement)  (continue, break, fallthrough, return)
            with/without condition statements
==================================================================== */
let names = ["Anna", "Alex", "Brian", "Jack"]
int a = 10

for name in names {
    print("Hello, \(name)!")
    if (a > 0) {
        break;
    }
}

for index in 1...5 {
    print("\(index) times 5 is \(index * 5)")
    break; //@violation
}

for name in names {
    print("Hello, \(name)!")
    continue;  //@violation
}

func greet(person: String) -> String {
    let greeting = "Hello, " + person + "!"
    return greeting
}

func greet(person: String) -> String {
    let greeting = "Hello, " + person + "!"
    return greeting

}

func greet2(person: String) -> String {
    let greeting = "Hello, " + person + "!"
    if (a == 1) {
        return greeting
    }
    int ig = 0;
}




