
Module Module1
    Sub Main()
        Dim decode1 As String = decoder.Decode(token, secret, verify:= false) '@violation

        Dim decode1Safe As String = decoder.Decode(token, secret, verify:= true)

        Dim decode2 As String = new JwtBuilder(). '@violation
            WithSecret(secret).
            Decode(forgedtoken1)

        Dim decode2Safe As String = new JwtBuilder().
            WithSecret(secret).
            MustVerifySignature().
            Decode(token)
    End Sub

End Module
