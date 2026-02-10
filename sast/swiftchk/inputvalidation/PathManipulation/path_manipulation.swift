//파싱성공
import Foundation

func function() {

    //let fileManager = FileManager.default
    //let fileManagerSec = FileManager()
    let path = getenv("PATH")


        let pathVar = String(validatingUTF8: path)



    let fileManager = FileManager.default
    let contents2 = try FileManager.default.contentsOfDirectory(path) //@violation
    let contents = try fileManager.contentsOfDirectory(pathVar) //@violation



}


func function2()  {



    guard let path = getenv("PATH") else {
        return
    }

    guard let pathVar = String(validatingUTF8: path) else {
        return
    }

    let fileManager = FileManager.default

    do {
    let contents = try fileManager.contentsOfDirectory(atPath: pathVar)
    } catch {
        return
    }
}

