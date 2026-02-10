import UIKit

func checkCaller()
{
    var host : NSHost = NSHost(address: getipaddr()) //@violation
    var host2 : NSHost = NSHost(globalgetipaddr) //@violation
    let someString2 = String("This is string 2.")
    println("test")
    var triNum: Float = 0.3 + 0.6 + 0.9
    var myNumber: Float = 0.3 + 0.6

    var str = "Hello, world"
    println(str)

    println(str)
}

