
func canVote(person:Person) -> Bool {


let url = NSURL(scheme:"http", host:"localhost:8080", path:"/igoat/user") //@violation
let request : NSMutableURLRequest = NSMutableURLRequest(URL:url)
let conn : NSURLConnection = NSURLConnection(request:request, delegate:self)
}
