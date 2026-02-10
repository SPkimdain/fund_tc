Public Class DataGlob
   Public Sub AddToSession(session As HttpSessionState)
     session("glob") = this '@violation
     session.add("glob", this) '@violation
   End Sub
End Class
