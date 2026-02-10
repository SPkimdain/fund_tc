Dim Val, Value
Set Val = Request.Form("val")
If IsNumeric(Val) Then
	Set Value = Val
Else
	App.EventLog "Failed to parse val=" & Val, 1 '@violation
End If