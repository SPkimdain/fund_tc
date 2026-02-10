/* WITH_CHECKERS : XSS_ERROR_MESSAGE_ASPNET */

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
    public partial class XSSError : System.Web.UI.Page
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
                throw new HttpException(503, string.Format("Invalid User Name: {0}", arg)); /* BUG: XSS_ERROR_MESSAGE_ASPNET */
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
                    throw new HttpException(503, string.Format("Invalid User Name: {0}", arg)); // Not bug
                }
                else
                {
                    Response.Write("BAD"); // Not bug
                }
            }
        }
    }
}