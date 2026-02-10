
public struct StderrOutputStream: OutputStreamType {
    public static let stream = StderrOutputStream()
    public func write(_ string: String) {fputs(string, stderr)}
}


func clamp(_ value:CGFloat, min:CGFloat, max:CGFloat)->CGFloat
{


    let errStream = StderrOutputStream.stream

    let deviceID = UIDevice.current.name

    print("Device ID: \(deviceID)", errStream) //@violation
    print("Device ID: \(UIDevice.current.name)", errStream) //@violation
       print("Device ID: \(UIDevice.current.name)", FileHandle.StandardError) //@violation


}


