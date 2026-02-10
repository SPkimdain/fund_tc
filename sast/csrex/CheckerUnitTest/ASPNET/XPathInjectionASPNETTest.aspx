<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="XPathInjectionASPNETTest.cs" Inherits="MyVulnerableWebsite.XPathValidation" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
<form id="form1" runat="server">
    <asp:TextBox ID="AccountIDTextBox" runat="server"></asp:TextBox>
    <asp:Button ID="Button1" Text="Go!" OnClick="OnClick_Good" runat="server"></asp:Button>
    <asp:Button ID="Button2" Text="Go!" OnClick="OnClick_Bad" runat="server"></asp:Button>
    <div>

    </div>
</form>
</body>
</html>
