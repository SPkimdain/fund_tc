Public Class UserRepository

    Public Shared Function TestSql(data As String)
        Dim dt As DataTable = Nothing
        dt = DbCommand.Exe("SELECT id FROM 9stones.view_access WHERE username = '" & data & "'") '@violation
        dt = DbCommand.Exe("SELECT memberId FROM access inner join 9stones.view_access on view_access.id = memberId WHERE username = @username limit 1;", New Hashtable From {{"@username", username}})
        Return dt
    End Function


End Class