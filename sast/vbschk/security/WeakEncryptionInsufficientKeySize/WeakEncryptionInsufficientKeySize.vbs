set rsa = CreateObject("Chilkat_9_5_0.Rsa")
success = rsa.GenerateKey(512) '@violation
If (success <> 1) Then
    outFile.WriteLine(rsa.LastErrorText)
    WScript.Quit
End If
