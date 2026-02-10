let key = "123456789012345678901234567890120"
let keyLength = UInt(kCCKeySizeAES256 + 1)
let keyPointer = strdup(key)    // Convert key to <UnsafeMutablePointer<Int8>

let message = "Don´t try to read this text. Top Secret Stuff"
let data = (message as NSString).dataUsingEncoding(NSUTF8StringEncoding)
let dataBytes = data?.bytes
let length = data?.length
let dataLength = UInt(length!)
let dataPointer = UnsafePointer<UInt8>(dataBytes!)

let operation: CCOperation = UInt32(kCCEncrypt)
let algoritm: CCAlgorithm = UInt32(kCCAlgorithmAES128)
let options: CCOptions = UInt32(kCCOptionECBMode + kCCOptionPKCS7Padding)

let cryptBufferSize = UInt(dataLength + kCCBlockSizeAES128)
var cryptBuffer = [UInt8](count: Int(cryptBufferSize), repeatedValue: 0)
var cryptBufferPointer = UnsafeMutablePointer<UInt8>(cryptBuffer)

var numBytesEncrypted = UnsafeMutablePointer<UInt>()

var cryptStatus = CCCrypt(operation, algoritm, options, "123456789012345678901234567890120", keyLength, nil, dataPointer, dataLength, cryptBufferPointer, cryptBufferSize, numBytesEncrypted) //@violation
