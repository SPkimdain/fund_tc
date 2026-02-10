
Partial Class _Default
    Inherits System.Web.UI.Page

    Protected Sub Page_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load
        Label1.Visible = False
        Label2.Visible = False
    End Sub

    Protected Sub Button1_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles Button1.Click
        Label1.Visible = True
        Label2.Visible = True
        Label1.Text = "input : " + TextBox1.Text '@violation
        Label2.Text = "You visited us at: " + DateTime.Now.ToString()

    End Sub
End Class