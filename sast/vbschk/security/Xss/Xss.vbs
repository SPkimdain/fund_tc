FUNCTION read
 read = Request.Form("test1")
END FUNCTION

SUB echo
    'do something
END SUB

dim a,b

a = Request.Form("test")
b = "test" & a

Response.Write b '@violation
Response.Write "SELECT " + read() '@violation

safeFilter(b)

Response.Write b '@violation