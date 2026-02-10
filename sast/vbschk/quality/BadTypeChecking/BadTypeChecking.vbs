dim uninit, bbs
bbs = 1
if IsEmpty(uninit) = false then
    if IsNumeric(uninit) = true then
        Response.Write "test"
    end if
end if

if IsNumeric(bbs) = true then
    Response.Write "number"
end if

if IsArray(uninit) = true then '@violation
    Response.Write "test"
end if