

func showConfirmBox(msg:String, title:String,
    firstBtnStr:String, firstSelector:(sampleParameter: String) -> returntype,
    secondBtnStr:String, secondSelector:() -> returntype,
    caller:UIViewController) {

    let url = NSURL(string: "https://www.somesvr.com/someapp/user")
    let request = NSMutableURLRequest(URL: "test")
    request.HTTPMethod = "GET"
    let connection = NSURLConnection(request:request, delegate:self) //@violation  "GET" method is used








    //Your Code
}




func showConfirmBoxSub(msg:String, title:String,
    firstBtnStr:String, firstSelector:(sampleParameter: String) -> returntype,
    secondBtnStr:String, secondSelector:() -> returntype,
    caller:UIViewController) {

    let url = NSURL(string: "https://www.somesvr.com/someapp/user")
    let request = NSMutableURLRequest(URL: "test")

    let connection = NSURLConnection(request:request, delegate:self) //@violation  uses undefined HTTP is set to be GET as default








    //Your Code
}
