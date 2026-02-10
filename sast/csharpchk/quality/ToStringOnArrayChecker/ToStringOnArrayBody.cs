using System;
using System.Configuration;
using System.Web;
using System.Web.Configuration;

namespace ToStringOnArray.TestApplication
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        Configuration config = WebConfigurationManager.OpenWebConfiguration(null);
        
        protected void Page_Load(object sender, EventArgs e)
        {
            string[] names0 = new string[3] {"Matt", "Joanne", "Robert" };
            names0.ToString(); // @violation
        }
    }
}