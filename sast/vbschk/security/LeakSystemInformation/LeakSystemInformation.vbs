If Err.number <>0 then
      Response.Write "An Error Has Occurred on this page!<BR>"
      Response.Write "The Error Number is: " & Err.number & "<BR>" '@violation
      Response.Write "The Description given is: " & Err.Description & "<BR>" '@violation
End If
