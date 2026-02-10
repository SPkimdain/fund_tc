import Foundation

var commandString = getenv("QUERY");

let ret = system(commandString) //@violation

