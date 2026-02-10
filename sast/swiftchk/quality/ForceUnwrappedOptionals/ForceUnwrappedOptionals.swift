import Cocoa

var greeting: String?
println( |(greeting!))  //@violation

if greeting != nil {
  println( |(greeting!)) //@violation
}

if let howdy = greeting {
  println(howdy)
}


var myString:String?
myString = "Hello, Swift!"
if myString != nil {
 println( myString! ) //@violation
}else{
 println("myString has nil value")
}
