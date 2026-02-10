import PerfectLDAP

// first create a connection

let connectionWIthData = try LDAP(url: "ldaps://...", loginData: login)
let connection = try LDAP(url: "ldaps:// ...") //@violation

// setup login info
let credential = LDAP.login( "anno" )

// login in a separated thread
connection.login(info: credential) { err in
  // if err is not nil, then something must be wrong in the login process.
}
