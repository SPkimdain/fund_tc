

func showConfirmBox(msg:String, title:String,
    firstBtnStr:String, firstSelector:(sampleParameter: String) -> returntype,
    secondBtnStr:String, secondSelector:() -> returntype,
    caller:UIViewController) {

    let password = "secret"
    let username = "scott"
    let con = DBConnect(username, password) //@violation

}