
func showConfirmBox(msg:String, title:String,
    firstBtnStr:String, firstSelector:(sampleParameter: String) -> returntype,
    secondBtnStr:String, secondSelector:() -> returntype,
    caller:UIViewController) {

context.evaluatePolicy(LAPolicy.DeviceOwnerAuthenticationWithBiometrics, localizedReason: "", reply: { (success, error) -> Void in //@violation
        if (success) {
            print("Auth was OK");
        }
        else {
            print("Error received: %d", error!);
        }
    })

}