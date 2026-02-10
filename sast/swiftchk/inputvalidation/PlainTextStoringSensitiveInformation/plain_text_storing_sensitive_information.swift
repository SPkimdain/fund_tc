import Foundation

var passWord = getImportantInformation()
let fileManager = FileManager()

let directory = fileManager.urls(for: .documentDirectory, in: .userDomainMask).first!

let dataPath = directory.appeningPathComponent("FileManager Directory")

let path = dataPath.appendingPathComponent("BadStore.txt")

let ret = passWord.write(to: path, atomically: false, encoding: .utf8) //@violation


