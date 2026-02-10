/* ====================================================================
 Author: Jiho Choi

 TEST CASE 04 - 1
 : DoNotChangePrecedenceAndAssociativityOfStandardOperators
 jump statement(= control statement + return statement)  (continue, break, fallthrough, return)
 with/without condition statements
 ==================================================================== */

import UIKit


precedencegroup Multiplicative {
    associativity: left
    higherThan: AdditionPrecedence
}
precedencegroup Exponentiative {
    associativity: left
    higherThan: Multiplicative
}

infix operator ** : Exponentiative
func **(lhs: Int, rhs: Int) -> Int {
    return Int(pow(Double(lhs), Double(rhs)))
}

// Output : 9
print(1 + 2 ** 3)

infix operator ***;

func ***(lhs: Int, rhs: Int) -> Int {
    return Int(pow(Double(lhs), Double(rhs)))
}

 precedencegroup SuperPowerPrecedence {
 associativity: right
 higherThan: MultiplicationPrecedence
 }

 infix operator +: SuperPowerPrecedence //@violation

 // Operator definition
 public func + (value1: Int, value2: Int) -> Int {
 return value1
 }

 let value = 10
 let power = 2

 // result = 100000
 var result:Int
 result = value + power * 2

 print(result)

infix operator + : Exponentiative //@violation

func +(lhs: Int, rhs: Int) -> Int {
    return Int(pow(Double(lhs), Double(rhs)))
}




