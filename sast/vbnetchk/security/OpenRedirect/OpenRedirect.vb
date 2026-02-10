
Partial Class _Default
    Protected Sub Button1_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles Button1.Click

        Dim url as String = Request.Form("dest")

        Response.Redirect(url) '@violation

    End Sub

End Class
