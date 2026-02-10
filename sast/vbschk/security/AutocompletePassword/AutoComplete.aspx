<%@ Page Language="vb" AutoEventWireup="false" CodeBehind="Index.aspx.vb" Inherits="EmailMigration.Index1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <meta name="robots" content="noindex,nofollow" />
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <meta name="description" content="" />
    <meta name="author" content="" />
    <title>Email Migration</title>
    <link href="../assets/css/main.css" rel="stylesheet" />
    <link href="../css/bootstrap.min.css" rel="stylesheet" />
</head>
<body>
    <form id="form1" runat="server">
        <div class="container margin-top-10">

            <asp:Label ID="Label1" runat="server" Text="Label"></asp:Label>

            <div class="form-group">
                <asp:TextBox ID="txtUsername" runat="server" placeholder="Username" CssClass="form-control"></asp:TextBox>
            </div>
                                    <div class="form-group">
                                        <asp:TextBox ID="txtPassword1" runat="server" placeholder="Password2" TextMode="Password" CssClass="form-control" ></asp:TextBox>
                                    </div>

                        <div class="form-group">
                            <asp:TextBox ID="txtPassword2" runat="server" placeholder="Password2" TextMode="Password" CssClass="form-control" autocomplete="off"></asp:TextBox>
                        </div>

            <asp:Button ID="btnLogin" runat="server" Text="Login" CssClass="btn btn-primary btn-block btn-lg" />
            <br />
            <p runat="server" id="msg" class="alert"></p>
        </div>
    </form>
</body>
</html>
