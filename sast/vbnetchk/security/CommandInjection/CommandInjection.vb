
Partial Class _Default
    Protected Sub Button1_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim cmd
        cmd = Request.Form("TextBox1")
        Shell(cmd) '@violation
    End Sub


End Class
