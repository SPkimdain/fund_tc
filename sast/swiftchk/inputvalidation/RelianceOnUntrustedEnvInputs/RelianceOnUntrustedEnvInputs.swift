import Foundation

func function() {

    let auth = getenv("PATH")
    let cookieContent = ["Set-Cookie": auth] // Or ["Set-Cookie": "key=value, key2=value2"] for multiple cookies

    // First
    let jar = HTTPCookieStorage.shared
    let cookieHeaderField = ["Set-Cookie": path] // Or ["Set-Cookie": "key=value, key2=value2"] for multiple cookies
    let cookies = HTTPCookie.cookies(withResponseHeaderFields: cookieContent, for: url) //@violation
    jar.setCookies(cookies, for: url, mainDocumentURL: url)

    // Then
    var request = URLRequest(url: url)



}


