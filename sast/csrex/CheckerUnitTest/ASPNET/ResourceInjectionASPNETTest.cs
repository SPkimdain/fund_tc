/* WITH_CHECKERS : RESOURCE_INJECTION_ASPNET */

using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
namespace MyVulnerableWebsite
{
    public partial class ResourceInject : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Request.Cookies["data"] != null)
            {
                HttpCookie cookie = Request.Cookies["data"];
                string path = cookie.Values["path"];
                using (FileStream fs = File.Open(path, FileMode.Open, FileAccess.Write, FileShare.None)) /* BUG: RESOURCE_INJECTION_ASPNET */
                {
                    Byte[] info = new UTF8Encoding(true).GetBytes("Test Text");
                    fs.Write(info, 0, info.Length);
                }
            }
        }
    }
}