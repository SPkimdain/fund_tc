using System;
using System.Configuration;
using System.Web.Configuration;

namespace TestApplication
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        Configuration config = WebConfigurationManager.OpenWebConfiguration(null);

        void Page_Load(object sender, EventArgs e)
        {
            HttpRuntimeSection hrs = (HttpRuntimeSection)config.GetSection("system.web/httpRuntime");
            TextBox1.Text = "" + hrs.EnableHeaderChecking;
            hrs.EnableHeaderChecking = false; // @violation
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            HttpRuntimeSection hrs = (HttpRuntimeSection)config.GetSection("system.web/httpRuntime");
            TextBox1.Text = "" + hrs.EnableHeaderChecking;
            hrs.EnableHeaderChecking = true;
            TextBox2.Text = "" + hrs.EnableHeaderChecking;
        }
    }
}