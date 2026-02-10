using System;
using System.Configuration;
using System.Web;
using System.Web.Configuration;

namespace TestApplication
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        Configuration config = WebConfigurationManager.OpenWebConfiguration(null);

        protected void Page_Load(object sender, EventArgs e)
        {
            // Create a new HttpCookie.
            HttpCookie vulnCookie = new HttpCookie("LastVisit", DateTime.Now.ToString());

            vulnCookie.Name = "MyHttpCookie";
            vulnCookie.Path = "/"; // @violation
            Response.AppendCookie(vulnCookie);

            Response.Write(vulnCookie.Name);
        }
    }
}