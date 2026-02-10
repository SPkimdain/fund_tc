Partial Class _Default
    Protected Sub Button1_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim newUser As String = "abc"

        ServicePointManager.ServerCertificateValidationCallback = Function(sender, certificate, chain, errors) True '@violation
    End Sub

    Protected Sub Button2_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles Button1.Click
        ServicePointManager.ServerCertificateValidationCallback =
            Function(sender, certificate, chain, errors)
                If Development Then Return True
                Return Errors = SslPolicyErrors.None AndAlso ValidCerts.Contains(certificate.GetCertHashString())
            End Function
    End Sub

End Class
