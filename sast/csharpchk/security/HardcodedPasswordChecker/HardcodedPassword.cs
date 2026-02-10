using System;
using System.IO;
using System.Web;

public class VulnerabilityTestCase : System.Web.UI.Page
{
	protected void Page_Load(object sender, EventArgs e)
	{
		string req_password = Request.QueryString["password"];

		if (req_password == "myPa55word")
		{
			// BAD: Set the password to a hardcoded string literal
			MembershipUser user = loadMembershipUser();
			user.ChangePassword("myNewPa55word"); // @violation
		}
	}
}