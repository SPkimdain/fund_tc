/* WITH_CHECKERS : LDAP_INJECTION_ASPNET */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.DirectoryServices;
using System.Text.RegularExpressions;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
namespace WebFormTest
{
    public partial class LDAPInjection : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void TextBox1_TextChanged(object sender, EventArgs e)
        {
            string arg = TextBox1.Text;
            DirectorySearcher src =
                 new DirectorySearcher(arg);

            src.SearchRoot = de;
            src.SearchScope = SearchScope.Subtree;

            foreach (SearchResult res in src.FindAll()) /* BUG: LDAP_INJECTION_ASPNET */
            {
				//Do something
            }
        }

        protected void TextBox2_TextChanged(object sender, EventArgs e)
        {
            string arg = TextBox2.Text;
            if (Regex.IsMatch(arg, "[a-zA-Z0-9]+")) {
                DirectorySearcher src =
                     new DirectorySearcher(arg);

                src.SearchRoot = de;
                src.SearchScope = SearchScope.Subtree;

                foreach (SearchResult res in src.FindAll()) // not bug
                {
                    //Do something
                }
            }
        }
    }
}