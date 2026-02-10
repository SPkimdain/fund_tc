Public Class ChildModel

    <Required(ErrorMessage:="Title is required")>
    Public Property Title() As String

End Class

Public Class ParentModel

    Public Property Title() As ChildModel '@violation

End Class

