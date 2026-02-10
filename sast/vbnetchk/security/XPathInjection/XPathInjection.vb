
Partial Class _Default
    Protected Sub Button1_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles Button1.Click

        Dim nav As XPathNavigator
        Dim strExpression As String
        Dim docNav as XPathDocument

        docNav = New XPathDocument("tmp.xml")
        nav = docNav.CreateNavigator
        strExpression = "sum(/path/something) div count(" & pathTextBox.Text & ")"

        Console.WriteLine("The value of the expression is {0}", nav.Evaluate(strExpression)) '@violation

    End Sub

End Class
