/* password : a!2@3b4a */
/* 비밀번호 : a!2@3b4a */
// This is a password : a!2@3b4a
func showConfirmBox(msg:String, title:String,
    firstBtnStr:String, firstSelector:(sampleParameter: String) -> returntype,
    secondBtnStr:String, secondSelector:() -> returntype,
    caller:UIViewController) {

    let password = getPassword() // password is "a!2@3b4a"
    let username = "scott"
    let con = DBConnect(username, password)

}