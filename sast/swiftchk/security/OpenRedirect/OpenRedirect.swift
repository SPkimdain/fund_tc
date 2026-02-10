import Foundation



let urll = URL(string: "http://www.google.com")

UIApplication.shared.openURL(urll) //@violation


UIApplication.shared.open(urll, options: [:], completionHandler: nil) //@violation

