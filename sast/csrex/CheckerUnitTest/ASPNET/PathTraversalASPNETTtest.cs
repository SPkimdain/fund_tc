/* WITH_CHECKERS : PATH_TRAVERSAL_ASPNET */

using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
namespace WebFormTest
{
    public partial class PathTraversal : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void TextBox1_TextChanged(object sender, EventArgs e)
        {
            string arg = TextBox1.Text;
            File.Delete(arg); /* BUG: PATH_TRAVERSAL_ASPNET */
        }

        protected void TextBox2_TextChanged(object sender, EventArgs e)
        {
            string arg = TextBox2.Text;
            if (arg.IndexOf('\\') > -1 || arg.IndexOf('/') > -1)
            {
                Response.Write("Bad File Name");
            }
            else
            {
                File.Delete(arg); // not bug
            }
        }
    }
}