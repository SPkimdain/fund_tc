ctl = Request.Form("ctl")
If String.Compare(ctl,"Add") = 0 Then
	ao.DoAddCommand Request
ElseIf String.Compare(ctl,"Modify") = 0 Then
	ao.DoModifyCommand Request
Else
	App.EventLog "No Action Found", 4
End If

ctl = Request.Form("ctl")
CallByName ao, ctl, vbMethod, Request '@violation

