import PerfectLDAP

let pass = getenv("PATH")
let credential = LDAP.Login(binddn: "CN=judy,CN=Users,DC=perfect,DC=com", password: pass) //@violation

let connection = LDAP(url: "ldaps://...", loginData: login)

