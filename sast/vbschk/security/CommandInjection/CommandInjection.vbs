btype = Request.Form("backuptype")
cmd = "cmd.exe /K " & "c:\util\rmanDB.bat " & btype
Shell cmd, vbNormalFocus '@violation

Dim oShell, path
Set oShell = WScript.CreateObject ("WScript.Shell")
path = Request.Form("Path")
oShell.run "cmd /K CD" & path & " & Dir" '@violation
Set oShell = Nothing


