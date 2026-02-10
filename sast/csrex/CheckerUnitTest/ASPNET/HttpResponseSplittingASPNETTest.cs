/* WITH_CHECKERS : HTTP_RESPONSE_SPLITTING_ASPNET */

using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
using System.Diagnostics;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
namespace MyVulnerableWebsite
{
    public class ResponseSplitting : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            BadCase(MessageTextBox);
            BadCase2(MessageTextBox);
            GoodCase(MessageTextBox);
            GoodCase2(MessageTextBox);
        }

        public void BadCase(TextBox box)
        {
            string id = box.Text;
            Response.AddHeader("Test", "Hi, " + id); /* BUG: HTTP_RESPONSE_SPLITTING_ASPNET */
        }

        public void BadCase2(TextBox box)
        {
            string id = Request.QueryString["ID"];
            Response.AddHeader("Test2", "Hi, " + id); /* BUG: HTTP_RESPONSE_SPLITTING_ASPNET */
        }

        public void GoodCase(TextBox box)
        {
            string id = box.Text.replace("\n", "");
            Response.AddHeader("Test", "Hi, " + id); // not bug
        }

        public void GoodCase2(TextBox box)
        {
            string id = Request.QueryString["ID"].replace("\n", "");
            Response.AddHeader("Test2", "Hi, " + id); // not bug
        }
    }
}