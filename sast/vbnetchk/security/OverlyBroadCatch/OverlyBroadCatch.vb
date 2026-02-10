
Module Module1

    Sub Main()
        Try
            Process.Start("http://www.fasoo.com")
        Catch ex As Exception '@violation
            Console.WriteLine("error")
        End Try




    End Sub

End Module