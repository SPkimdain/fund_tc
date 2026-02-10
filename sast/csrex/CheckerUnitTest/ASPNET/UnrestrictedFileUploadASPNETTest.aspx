<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="UnrestrictedFileUploadASPNETTest.cs" Inherits="WebFormTest.UnrestrictedUpload" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
<form id="form1" runat="server">
    <asp:Label ID="StatusLabel" runat="server" Text="Label"></asp:Label>
    <asp:FileUpload ID="FileUpload1" runat="server"></asp:FileUpload>
    <asp:Button ID="UploadButton" TEXT="Upload File" onclick="UploadButton_Click" runat="server"></asp:Button>
    <asp:Button ID="UploadButton2" TEXT="Upload File" onclick="UploadButton_Click2" runat="server"></asp:Button>
    <div>

    </div>
</form>
</body>
</html>