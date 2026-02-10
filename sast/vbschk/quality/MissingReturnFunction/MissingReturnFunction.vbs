Function test1 (a,b)
    if (a>0) then
        test1 = b
    else
        test1 = a
    end if
    Response.write a&b
End Function


Function test2 (a,b) '@violation
    Response.Write a&b
End Function

Function test3(c) '@violation
    if (c>0) then
        test3 = c
    end if
    Response.Write c
End Function

Function test4(d)
    Select Case d
        Case 1
            test4 = 0
        Case 2
            test4 = 1
    End Select
End Function