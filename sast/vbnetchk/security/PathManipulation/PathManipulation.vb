
Module Module1

    Sub Main()

        Dim path as String
        path = Request.Form("path")

        Dim fs as FileStream = File.Create(path) '@violation


    End Sub

End Module