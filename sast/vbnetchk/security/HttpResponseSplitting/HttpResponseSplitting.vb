
Partial Class _Default
    Protected Sub Button1_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim a
        a = Request.Form("TextBox1")
        Response.AddHeader ("foo" , "bar" + a)'@violation
    End Sub


End Class
