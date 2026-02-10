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
            HttpCookie vulnCookie = new HttpCookie("LastVisit", DateTime.Now.ToString()); // @violation
            // By default, the HttpOnly property is set to false 
            // unless specified otherwise in configuration.

            vulnCookie.Name = "MyHttpCookie";
            Response.AppendCookie(vulnCookie);

            // Show the name of the cookie.
            Response.Write(vulnCookie.Name);

            // Create an HttpOnly cookie.
            HttpCookie HttpOnlyCookie = new HttpCookie("LastVisit", DateTime.Now.ToString());

            // Setting the HttpOnly value to true, makes
            // this cookie accessible only to ASP.NET.

            HttpOnlyCookie.HttpOnly = true;
            HttpOnlyCookie.Name = "MyHttpOnlyCookie";
            Response.AppendCookie(HttpOnlyCookie);

            // Show the name of the HttpOnly cookie.
            Response.Write(HttpOnlyCookie.Name);
        }
    }
}