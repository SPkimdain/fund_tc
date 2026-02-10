
func showConfirmBox(msg:String, title:String,
    firstBtnStr:String, firstSelector:(sampleParameter: String) -> returntype,
    secondBtnStr:String, secondSelector:() -> returntype,
    caller:UIViewController) {

let ITERATION = UInt32(10)


CCHmac(UInt32(kCCHmacAlgSHA256), "", 0, plaintext, plaintextLen, &output)


            let secure: Bool



let salt = "2!@$(5#@532@%#$253l5#@$"

CCKeyDerivationPBKDF(CCPBKDFAlgorithm(kCCPBKDF2), password, passwordLength, nil, 0, CCPseudoRandomAlgorithm(kCCPRFHmacAlgSHA256), ITERATION, derivedKey, derivedKeyLength) //@violation






 let properties = [
            HTTPCookiePropertyKey.domain: ".example.com",
            HTTPCookiePropertyKey.path: "/service",
            HTTPCookiePropertyKey.name: "foo",
            HTTPCookiePropertyKey.value: "bar",
            HTTPCookiePropertyKey.secure: true,
             HTTPCookiePropertyKey.exipres : NSDate(timeIntervalSinceNow: (60*60*24*365*10))
             ] as [HTTPCookiePropertyKey : Any]






        let cookie = HTTPCookie(properties: properties)






    //Your Code
}



func sha256(data : Data) -> Data {
    var hash = [UInt8](repeating: 0,  count: Int(CC_SHA256_DIGEST_LENGTH))
    data.withUnsafeBytes {
        _ = CC_SHA256($0, CC_LONG(data.count), &hash)
    }
    return Data(bytes: hash)
}


extension String {

    func sha256() -> String {
        if let stringData = self.data(using: String.Encoding.utf8) {
            return hexStringFromData(input: digest(input: stringData as NSData))
        }
        return ""
    }

    private func digest(input : NSData) -> NSData {
        let digestLength = Int(CC_SHA256_DIGEST_LENGTH)
        var hash = [UInt8](repeating: 0, count: digestLength)
        CC_SHA256(input.bytes, UInt32(input.length), &hash)
        return NSData(bytes: hash, length: digestLength)
    }

    private func hexStringFromData(input: NSData) -> String {
        var bytes = [UInt8](repeating: 0, count: input.length)
        input.getBytes(&bytes, length: input.length)

        var hexString = ""
        for byte in bytes {
            hexString += String(format:"%02x", UInt8(byte))
        }

        return hexString
    }

}
