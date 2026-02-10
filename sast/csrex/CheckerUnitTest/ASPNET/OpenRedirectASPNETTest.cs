/* WITH_CHECKERS : OPEN_REDIRECT_ASPNET */

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
    public partial class OpenRedirect : System.Web.Mvc.ViewPage
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void TextBox1_TextChanged(object sender, EventArgs e)
        {
            string arg = TextBox1.Text;
            Response.Redirect(arg); /* BUG: OPEN_REDIRECT_ASPNET */
        }

        protected void TextBox2_TextChanged(object sender, EventArgs e)
        {
            string arg = TextBox2.Text;
            if (Url.IsLocalUrl(arg)) {
                Response.Redirect(arg); // not bug
            }
            else if (!arg.StartsWith("https:") && !arg.StartsWith("http:") && Url.IsWellFormedUriString(arg, UriKind.Relative))
            {
                Response.Redirect(arg); // not bug
            }
        }
    }
}