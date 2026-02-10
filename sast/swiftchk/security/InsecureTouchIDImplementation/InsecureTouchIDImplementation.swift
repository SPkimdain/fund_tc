import UIKit

func temp()
{
  var context:LAContext = LAContext(); //@violation
  var error:NSError?
  var success:Bool;
  var reason:String = "Please authenticate using TouchID.";

  if (context.canEvaluatePolicy(LAPolicy.DeviceOwnerAuthenticationWithBiometrics, error: &error))
  {
      context.evaluatePolicy(LAPolicy.DeviceOwnerAuthenticationWithBiometrics, localizedReason: reason, reply: { (success, error) -> Void in
          if (success) {
              println("Auth was OK");
          }
          else
          {
              //You should do better handling of error here but I'm being lazy
              println("Error received: %d", error!);
          }
      });
  }
}

