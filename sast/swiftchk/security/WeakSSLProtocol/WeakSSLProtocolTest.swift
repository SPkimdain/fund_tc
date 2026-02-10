
func showConfirmBox(msg:String, title:String,
    firstBtnStr:String, firstSelector:(sampleParameter: String) -> returntype,
    secondBtnStr:String, secondSelector:() -> returntype,
    caller:UIViewController) {



let configuration : NSURLSessionConfiguration = NSURLSessionConfiguration.defaultSessionConfiguration()
configuration.TLSMinimumSupportedProtocol = kSSLProtocol3Only //@violation
configuration.TLSMinimumSupportedProtocol = kSSLProtocol2 //@violation
configuration.TLSMinimumSupportedProtocol = kSSLProtocolAll //@violation
configuration.TLSMinimumSupportedProtocol = kTLSProtocol1Only //@violation

let mySession = NSURLSession(configuration: configuration, delegate: self, delegateQueue: operationQueue)

    //Your Code
}

