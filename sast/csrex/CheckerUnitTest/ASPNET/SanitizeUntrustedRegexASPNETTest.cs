/* WITH_CHECKERS : SANITIZE_UNTRUSTED_DATA_PASSED_TO_A_REGEX_ASPNET */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Text.RegularExpressions;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
namespace MyVulnerableWebsite
{
    public partial class UntrustedRegex : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            string regexUser = Request.QueryString["user-defined regex"];
            string pattern = "(.* +public\\[\\d+\\] +.*" + regexUser + ".*)";
            Regex regex = new Regex(pattern); /* BUG: SANITIZE_UNTRUSTED_DATA_PASSED_TO_A_REGEX_ASPNET */
            Match match = regex.Match("private containing string");
        }
    }
}