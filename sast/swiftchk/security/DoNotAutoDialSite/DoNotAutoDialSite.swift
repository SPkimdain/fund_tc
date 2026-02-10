
func showConfirmBox(msg:String, title:String,
    firstBtnStr:String, firstSelector:(sampleParameter: String) -> returntype,
    secondBtnStr:String, secondSelector:() -> returntype,
    caller:UIViewController) {

    var webView = WKWebView()
    let webUrl : URL = URL(string: "https://some.site..com/")!
    let webRequest : URLRequest = URLRequest(url: webUrl )
    webView.loadRequest(webRequest) //@violation

    //Your Code
}
