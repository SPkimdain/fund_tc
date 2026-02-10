let keyString        = "12345678901234567890123456789012"
let keyData: NSData! = (keyString as NSString).dataUsingEncoding(NSUTF8StringEncoding) as NSData!
print("keyLength   = \(keyData.length), keyData   = \(keyData)")

let message       = "Don´t try to read this text. Top Secret Stuff"
let data: NSData! = (message as NSString).dataUsingEncoding(NSUTF8StringEncoding) as NSData!
print("data length = \(data.length), data      = \(data)")

let cryptData    = NSMutableData(length: Int(data.length) + kCCBlockSizeAES128)!

let keyLength              = size_t(kCCKeySizeAES256)
let operation: CCOperation = UInt32(kCCEncrypt)
let algoritm:  CCAlgorithm = UInt32(kCCAlgorithmAES128)
//let options:   CCOptions   = UInt32(kCCOptionECBMode + kCCOptionPKCS7Padding)
let options:   CCOptions   = UInt32(kCCOptionECBMode)

var numBytesEncrypted :size_t = 0

var cryptStatus = CCCrypt(operation,
    algoritm,
    options, //@violation
    keyData.bytes, keyLength,
    nil,
    data.bytes, data.length,
    cryptData.mutableBytes, cryptData.length,
    &numBytesEncrypted)

if UInt32(cryptStatus) == UInt32(kCCSuccess) {
    cryptData.length = Int(numBytesEncrypted)
    print("cryptLength = \(numBytesEncrypted), cryptData = \(cryptData)")

    // Not all data is a UTF-8 string so Base64 is used
    let base64cryptString = cryptData.base64EncodedStringWithOptions(.Encoding64CharacterLineLength)
    print("base64cryptString = \(base64cryptString)")

} else {
    print("Error: \(cryptStatus)")
}