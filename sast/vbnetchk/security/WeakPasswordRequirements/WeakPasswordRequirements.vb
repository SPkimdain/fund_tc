
Partial Class _Default
    Protected Sub Button1_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles Button1.Click

        Dim newUser As MembershipUser = Membership.CreateUser(UsernameTextbox.Text, PasswordTextbox.Text) '@violation

    End Sub

End Class
