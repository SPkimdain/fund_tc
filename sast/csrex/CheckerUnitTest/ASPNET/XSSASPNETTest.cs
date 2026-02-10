/* WITH_CHECKERS : XSS_ASPNET */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
namespace WebFormTest
{
    public partial class XSS : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void TextBox1_TextChanged(object sender, EventArgs e)
        {
            string arg = TextBox1.Text;
            MembershipUser user = Membership.GetUser(arg);
            if (user != null)
            {
                // Do something
            }
            else
            {
                Response.Write("Invalid User Name: " + arg); /* BUG: XSS_ASPNET */
            }
        }

        protected void TextBox2_TextChanged(object sender, EventArgs e)
        {
            string arg = TextBox2.Text;
            MembershipUser user = Membership.GetUser(arg);
            if (user != null)
            {
                // Do something
            }
            else
            {
                if (arg.IndexOf('\\') > -1 || arg.IndexOf('/') > -1)
                {
                    Response.Write("Invalid User Name: " + arg); // Not bug
                }
                else
                {
                    Response.Write("BAD"); // Not bug
                }
            }
        }
    }
}