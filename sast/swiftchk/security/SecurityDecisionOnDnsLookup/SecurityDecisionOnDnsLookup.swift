//: # How to retrieve a host name and associated aliases from an IP address
//: Rename the file extension to `playground` and run it directly in Xcode 7 with Swift 2.
import Cocoa
//: ## Using the C `struct`s in Swift
//: We can safely use a Swift `String` for storing the IP address in charachter format as Swift supports toll-fee bridging to C strings.
let ip = "17.172.224.47"
//: In order to use the `hostent` C structure as a reference value (pointer) we have to declare it as an `UnsafeMutablePointer` of the corresponding type.
//: We use `let` as the value itself will never change, but only the reference to the value. As such, the value (not the reference, or pointer for that matter) will be a constant.
let he: UnsafeMutablePointer<hostent>
//: We can declare another constant of type `hostent` which will be type-compatible with the memory location of `he`'s pointer to the C structure.
let he2: hostent
//: We create an empty fully initialized `in_addr` C structure by using the convenience initializer.
var addr: in_addr = in_addr()
/*:
Now, the following declaration of a constant is a bit awkward. It uses Swift's C-bridging types to denote a `char **` which represents a pointer to a list of `char` pointers, which in turn represents an array of C strings.
Swift translates the C `char` to a `CChar` and the `*` pointer to a `UnsafeMutablePointer`, so the notation
`char **`
is mapped by reading right-to-left to
`UnsafeMutablePointer<UnsafeMutablePointer<CChar>>`
*/
let host_list: UnsafeMutablePointer<UnsafeMutablePointer<CChar>>
//: To store the host names in a plain Swift array of `String`s we use the following variable.
var host_aliases: [String] = []
//: ## Using the C Standard Library
//: The C Standard Library function `inet_pton` converts an IP address from a string representation to a network number. `AF_INET` tells the function to expect an IP4 address.
//: Caveat: Some functions require the `AF_…` constants to be wrapped around an `sa_family_t()` type cast.
inet_pton(AF_INET, ip, &addr)
//: Now we can all the legacy `gethostbyaddr` C function which returns a pointer to a `hostent` structure.
he = gethostbyaddr(&addr, UInt32(sizeof(in_addr)), AF_INET) //@violation
//: For convenience we use the `memory` member of the `he` structure to assign the value of the structure to the `he2` constant. This leaves us with shorter member access names and also shows the type conversion between Swift's C-bridging pointer types and `struct` types.
he2 = he.memory
//: The first resolved host name is present as an optional C string in `hostent`'s member `h_name`.
//: Just print it out, and then append it to the `host_aliases` array of `String`s.
print("First canonical host name: \(String.fromCString(he2.h_name)!)")
host_aliases.append(String.fromCString(he2.h_name)!)
//: Again for convenience, we assign the pointer to the list of C strings containing the alias names of the host to a constant name.
host_list = he2.h_aliases
//: ## Converting the list of C strings to a Swift `String` array
//: We use a zero-initialized Int for looping over the list of C strings.
var i = 0
/*:
This is the beauty of Swift's toll-free C-bridging at a max: We can simply refer to the list of C strings using the standard Swift array accessor.
Combined with the conditional optional unwrapping directly in the `while` loop we get a very concise expression for
iterating over the NULL-terminated list, converting the C strings into `String`s and and packing the `String`s into the Swift array of `Strings`.
Notice the `++i` implicit incrementation: We skip the first alias name as it represents the RARP address pointer (`47.224.172.17.in-addr.arpa`) which is of no use to us.
*/
while let h = String.fromCString(host_list[++i]) {
    host_aliases.append(h)
}
//: ## The result
//: Having now a Swift array of `Strings` filled up with the host names, working with it in either the Playground or in code is nice and clean.
print("Found \(host_aliases.count) hosts for IP address \(ip):")
for host in host_aliases {
    print(host)
}