using System;
using System.IO;
using System.Web;

public class CWE209TestCase : System.Web.UI.Page
{
	protected void Page_Load(object sender, EventArgs e)
	{
		string reqPayload = Request.QueryString["payload"];
		try
		{
			doSomeWork();
		}
		catch (Exception ex)
        {
			// BAD: printing a stack trace back to the response
			Response.Write(ex.ToString()); // @violation
			Debug.Writeline(ex.ToString()); // @violation
			Response.Read(ex.ToString());
			return;
		}
	}
}