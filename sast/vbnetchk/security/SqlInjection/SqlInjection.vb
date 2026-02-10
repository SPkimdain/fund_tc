
Partial Class _Default
    Protected Sub Button1_Click(ByVal sender As Object, ByVal e As System.EventArgs, ByRef AFTableAreaMst As エリアマスタ) Handles Button1.Click

        Dim SqlStr As String

        Dim SqlConn As New SqlConnection()
        Dim SqlCmd As New SqlCommand()

        SqlConn.ConnectionString = "blahblah"

        SqlStr = "SELECT * FROM tbl WHERE ID = \'" & IdTextBox.Text & "\'"

        SqlCmd.CommandText = SqlStr '@violation
    End Sub

    Protected Sub Button2_Click(ByVal sender As Object, ByVal e As System.EventArgs, ByRef AFTableAreaMst As エリアマスタ) Handles Button1.Click

        Dim SqlStr As String

        Dim SqlConn As New SqlConnection()
        Dim SqlCmd As New SqlCommand()

        SqlConn.ConnectionString = "blahblah"

        SqlStr = "SELECT * FROM tbl WHERE ID = \'" & IdTextBox.Text & "\'"

        SqlStr = safeFilter(SqlStr)

        SqlCmd.CommandText = SqlStr '@violation
    End Sub

End Class


