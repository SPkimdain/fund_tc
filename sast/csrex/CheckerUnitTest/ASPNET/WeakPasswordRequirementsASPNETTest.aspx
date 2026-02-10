<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WeakPasswordRequirementsASPNETTest.cs" Inherits="MyVulnerableWebsite.WeakPassword" %>

        <!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
<form id="form1" runat="server">
    <asp:Label ID="Label1" runat="server" Text="Label"></asp:Label>
    <asp:TextBox ID="UserName" runat="server"></asp:TextBox>
    <asp:HiddenField ID="Password" value="" runat="server"></asp:TextBox>
    <asp:Button ID="CreateUserButton" Text="CreateUser" OnClick="CreateUser_OnClick" runat="server"></asp:Button>
    <asp:Button ID="CreateUserButton2" Text="CreateUserSafe" OnClick="CreateUser_OnClick2" runat="server"></asp:Button>
    <div>

    </div>
</form>
</body>
</html>
