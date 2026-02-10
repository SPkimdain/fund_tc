import Foundation

let myURLstring = "http://www.safety.vanderbilt.edu/images/staff/Bob-Wheaton.jpg"
let myFilePathString = "/Volumes/HD/Staff Pictures/Bob-VEHS.jpg"

let pass = getenv("PATH")

let url = NSURL( pass)
let imageDataFromURL = NSData(contentsOfURL: url)

let fileManager = NSFileManager.defaultManager()
fileManager.createFileAtPath(myFilePathString, contents: imageDataFromURL, attributes: nil) //@violation





var vendingMachine = VendingMachine()
vendingMachine.coinsDeposited = 8
do {
    try buyFavoriteSnack(person: "Alice", vendingMachine: vendingMachine)
    print("Success! Yum.")
} catch {
    print("Unexpected error: \(error).")
}