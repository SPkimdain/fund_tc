author = Request.Form(AUTHOR_PARAM)
Response.Cookies("author") = author '@violation
Response.Cookies("author").Expires = cookieExpiration