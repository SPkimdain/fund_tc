
Partial Class _Default
    Protected Sub Button1_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles Button1.Click


        Dim strExpression As String
        strExpression = "for $x in document(""" & Request.Form("doc") & """" & _
                    "....."

        Dim expr As new XQueryExpression(strExpression) '@violation

        'some codes for XQueryExpression

    End Sub

End Class
