
/* ====================================================================
    Author: Jiho Choi

    TEST CASE 03 - 2    JumpShouldNotBeFollowedByOthers

        control statements cases

==================================================================== */
func greet1(person: String) -> String {
    let greeting1 = "Hello, " + person + "!"

    let names = ["Anna", "Alex", "Brian", "Jack"]
    int a = 10
    for name in names {
        print("Hello, \(name)!")
        if (a > 0) {
            break;
        }
    }

    for name in names {
        print("Hello, \(name)!")
        if (a > 0) {
            break; //@violation
            a = 100;
        }
    }

    for index in 1...5 {
        print("\(index) times 5 is \(index * 5)")
        break; //@violation
        a = 1000;
    }

    for name in names {
        print("Hello, \(name)!")
        continue; //@violation
        a = 1000;
    }

    return greeting1 //@violation
    a = 100000;
}



/* ====================================================================
    Author: Jiho Choi

    TEST CASE 03 - 1    JumpShouldNotBeFollowedByOthers

        return statements cases

==================================================================== */

func greet1(person: String) -> String {
    let greeting1 = "Hello, " + person + "!"
    return greeting1
}

func greet2(person: String) -> String {
    let greeting2 = "Hello, " + person + "!"
    let i = 0;
    return greeting2 //@violation
    i = 10;
}

func greet3(person: String) -> String {
    let greeting3 = "Hello, " + person + "!"
    let notGreeting3 = "Hello, " + person + "!"
    if a == 10 {
        return notGreeting3
    }
    return greeting3
}

func greet4(person: String) -> String {
    let greeting4 = "Hello, " + person + "!"
    let notGreeting4 = "Hello, " + person + "!"
    return greeting4 //@violation
    if a == 10 {
        return notGreeting4
    }
}

func greet5(person: String) -> String {
    let greeting5 = "Hello, " + person + "!"
    let notGreeting5 = "Hello, " + person + "!"
    let i = 10;
    if i == 10 {
        return notGreeting5 //@violation
        i = 0;
    }
    return greeting5
}

func greet6(person: String) -> String {
    let greeting6 = "Hello, " + person + "!"
    let notGreeting6 = "Hello, " + person + "!"
    let i = 10;
    if i == 10 {
        return notGreeting6 //@violation
        i = 0;
    }
    return greeting6 //@violation
    i = 1;
}

