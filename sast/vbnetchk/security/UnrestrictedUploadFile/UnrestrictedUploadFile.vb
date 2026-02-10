
Partial Class _Default
    Protected Sub Button1_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles Button1.Click

        Dim savePath as String = Request.Form("path")
        Dim fileName as String = FileUpload1.FileName

        FileUpload1.SaveAs(savePath + fileName) '@violation

    End Sub

End Class
