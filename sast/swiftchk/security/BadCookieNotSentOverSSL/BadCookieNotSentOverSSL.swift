
func showConfirmBox(msg:String, title:String,
    firstBtnStr:String, firstSelector:(sampleParameter: String) -> returntype,
    secondBtnStr:String, secondSelector:() -> returntype,
    caller:UIViewController) {



            let secure: Bool



            var properties: [HTTPCookiePropertyKey: Any] =
                        [HTTPCookiePropertyKey.name: name,
                         HTTPCookiePropertyKey.value: encodedSessionId,
                         HTTPCookiePropertyKey.domain: domain,

                         HTTPCookiePropertyKey.path: path]







        let cookie = HTTPCookie(properties: properties) //@violation






    //Your Code
}



func showConfirmBoxSub(msg:String, title:String,
    firstBtnStr:String, firstSelector:(sampleParameter: String) -> returntype,
    secondBtnStr:String, secondSelector:() -> returntype,
    caller:UIViewController) {



            let secure: Bool



            var properties: [HTTPCookiePropertyKey: Any] =
                        [HTTPCookiePropertyKey.name: name,
                         HTTPCookiePropertyKey.value: encodedSessionId,
                         HTTPCookiePropertyKey.domain: domain,
                         HTTPCookiePropertyKey.path: path]

                properties[HTTPCookiePropertyKey.secure] = "Yes"





        let cookie = HTTPCookie(properties: properties)






    //Your Code
}

