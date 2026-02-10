
Partial Class _Default
    Protected Sub Button1_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles Button1.Click

        Dim path as String = "LDAP://CN=users,DC=fasoo,DC=com"
        Dim entry as New DirectoryEntry(path)

        Dim searcher as New DirectorySearcher(entry)

        searcher.Filter = "(&(objectClass=user)(anr=" + Request.Form("username") + "*))" '@violation

        Dim results As SearchResultCollection = searcher.FildAll()

    End Sub

End Class
