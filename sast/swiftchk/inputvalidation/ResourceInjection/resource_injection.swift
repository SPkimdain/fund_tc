import Foundation
import UIKit

func function() {
  var queryString = getenv("QUERY");

  var readStream:  Unmanaged<CFReadStream>?
  var writeStream: Unmanaged<CFWriteStream>?

  CFStreamCreatePairWithSocketToHost(nil, queryString, 777, &readStream, &writeStream) //@violation

}
