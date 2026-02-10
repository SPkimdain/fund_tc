


func checkAuthSecTrustEvaluate()
{

    let trust = challenge.protectionSpace.serverTrust
    var secresult = SecTrustResultType.Invalid
    let status = SecTrustEvaluate(trust!,&secresult)  //@violation 
    completionHandler(Foundation.URLSession.AuthChallengeDisposition.useCredential, challenge.proposedCredential) 
}





func checkAuthSecTrustEvaluate3()
{

    let trust = challenge.protectionSpace.serverTrust
    var secresult = SecTrustResultType.Invalid
    
    
    if (SecTrustEvaluate(serverTrust, &secresult) != errSecSuccess){
   return;
    }
    
}



func checkAuthSecTrustEvaluate2()
{

    let trust = challenge.protectionSpace.serverTrust
    var secresult = SecTrustResultType.Invalid
    let status = SecTrustEvaluate(trust!,&secresult)
    
    if (secresult){
        return;
    }
    
}
