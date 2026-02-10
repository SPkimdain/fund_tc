/* WITH_CHECKERS : RELIANCE_ON_UNTRUSTED_INPUTS_IN_A_SECURITY_DECISION_ASPNET */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
namespace MyVulnerableWebsite
{
    public partial class DecisionOnCookies : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Request.Cookies["data"] != null)
            {
                HttpCookie cookie = Request.Cookies["data"];
                string role = cookie.Values["role"];
                if (role.Equals("admin")) /* BUG: RELIANCE_ON_UNTRUSTED_INPUTS_IN_A_SECURITY_DECISION_ASPNET */
                {
                    Response.Write("You are an admin!");
                }
                Response.Write("access denied!");
            }
        }
    }
}