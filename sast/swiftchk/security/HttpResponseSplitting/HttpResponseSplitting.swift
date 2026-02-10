let aString = getenv("PATH")
let newString = aString.replacingOccurrences(of: " ", with: "+", options: .literal, range: nil)

var request = URLRequest(url: url)
request.setValue("secret-keyValue", forHTTPHeaderField: aString) //@violation


URLSession.shared.dataTask(with: aString)




var request2 = URLRequest(url: url)
request2.setValue("secret-keyValue", forHTTPHeaderField: newString)

URLSession.shared.dataTask(with: request2)

