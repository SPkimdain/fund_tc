
func showConfirmBox(msg:String, title:String,
    firstBtnStr:String, firstSelector:(sampleParameter: String) -> returntype,
    secondBtnStr:String, secondSelector:() -> returntype,
    caller:UIViewController) {

let emptystring = ""
context.evaluatePolicy(LAPolicy.DeviceOwnerAuthenticationWithBiometrics, localizedReason: emptystring, reply: { (success, error) -> Void in //@violation
        if (success) {
            print("Auth was OK");
        }
        else {
            print("Error received: %d", error!);
        }
    })

}