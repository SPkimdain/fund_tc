let dataPath = documentsDirectory.appendingPathComponent("FileManger Directory")
let dataPath2 = documentsDirectory.appendingPathComponent("FileManger Directory")

// FileManagerTest.swift에 추가

    // 파일 이름을 기존의 경로에 추가
    let helloPath = dataPath.appendingPathComponent("Hello.txt")

    // 내용 읽기
    let text2 = try String(contentsOf: helloPath, encoding: .utf8) //@violation

    print(text2)




do {
    // 파일 이름을 기존의 경로에 추가
    let helloPath = dataPath2.appendingPathComponent("Hello.txt")

    // 내용 읽기
    let text2 = try String(contentsOf: helloPath, encoding: .utf8)

    print(text2)
}
catch let error as NSError {
    print("Error Reading File : \(error.localizedDescription)")
}
