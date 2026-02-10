/* WITH_CHECKERS : WEAK_PASSWORD_REQUIREMENTS_ASPNET */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.Security;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
namespace MyVulnerableWebsite
{
    public partial class WeakPassword : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        public void CreateUser_OnClick(object sender, EventArgs args)
        {
            try
            {
                MembershipUser newUser = Membership.CreateUser(UserName.Text, Password.Value); /* BUG: WEAK_PASSWORD_REQUIREMENTS_ASPNET */
                Response.Redirect("login.aspx");
            }
            catch (MembershipCreateUserException e)
            {
            }
        }

        public void CreateUser_OnClick2(object sender, EventArgs args)
        {
            try
            {
                string pass = Password.Text;
                if (pass.Length >= 8) // Length constraint
                {
                    if (Regex.IsMatch(pass, ".*[!@#\\$%\\^\\&\\*\\(\\)\\?\\+].*") && Regex.IsMatch(pass, ".*[0-9].*")) // Special char & number char constraint
                    {
                        MembershipUser newUser = Membership.CreateUser(UserName.Text, Password.Text); // SAFE
                        Response.Redirect("login.aspx");
                    }
                }
            }
            catch (MembershipCreateUserException e)
            {
            }
        }
    }
}