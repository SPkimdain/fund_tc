
Public Class DataGlob


   Public Sub Login_OnClick(session As HttpSessionState)
     FormsAuthentication.RedirectFromLoginPage(Username.Text, true) '@violation
   End Sub
End Class
