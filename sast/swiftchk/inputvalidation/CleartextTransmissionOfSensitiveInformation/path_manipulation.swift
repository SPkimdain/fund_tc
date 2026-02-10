import Foundation

func function() {

    let auth = getPassword()
    let addr = "192.168.1.45"
    let port = 22090
    let client:TCPClient = TCPClient(addr: "192.168.1.45", port: 22090)
    var (success,errmsg)=client.connect(timeout: 1)
    if success{
        var (success,errmsg)=client.send(str:auth ) //@violation
        if success{
            let data=client.read(1024*10)
            if let d=data{
                if let str=String(bytes: d, encoding: String.Encoding.utf8){
                    print(str)
                }
            }
        } else {
            print(errmsg)
        }
    } else {
        print(errmsg)
    }






}


