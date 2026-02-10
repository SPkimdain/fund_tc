
set a = Request.Form("UserName")
rs = db.execute("SELECT * FROM tblUSERS WHERE UserName = '" & a ) '@violation


sub test1 (str)
    rsaddforum.open "SELECT " & str, oconn, adOpenDynamic, adLockPessimistic
end sub

test1 Request.Form("asfd") '@violation



