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
            vulnCookie.Domain = ".example.com"; // @violation
            vulnCookie.Domain = "example.com"; // @violation
            vulnCookie.Domain = "exception.com";

            // Below Domain is custom domain which you want to detect optionally
            vulnCookie.Domain = "insecure.example.com"; // @violation
            Response.AppendCookie(vulnCookie);

            Response.Write(vulnCookie.Name);
        }
    }
}