
func showConfirmBox(msg:String, title:String,
    firstBtnStr:String, firstSelector:(sampleParameter: String) -> returntype,
    secondBtnStr:String, secondSelector:() -> returntype,
    caller:UIViewController) {




let messageComposeVC = MFMessageComposeViewController() //@violation
messageComposeVC.messageComposeDelegate = self
messageComposeVC.body = "Hello World!"
messageComposeVC.recipients = ["+12345678910"]

presentViewController(messageComposeVC, animated: true, completion: nil)


UIApplication.sharedApplication().openURL(NSURL(string: "sms:+12345678910")) //@violation


    //Your Code
}

