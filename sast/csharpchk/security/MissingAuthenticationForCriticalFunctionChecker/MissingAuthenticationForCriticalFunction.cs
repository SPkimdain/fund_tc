using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Web;

namespace NewNonghyupCheckers
{
    class MissingAuthentication : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e) {
            //
        }

        protected void LoginButton_Click(object sender, EventArgs e) {
            if(Membership.ValidateUser(UserName.Text, Password.Text)) {
                FormsAuthentication.RedirectFromLoginPage(UserName.Text, RememberMe.Checked); //safe
            }
        }

        protected void LoginButton_Click(object sender, EventArgs e) {
            FormsAuthentication.RedirectFromLoginPage(UserName.Text, RememberMe.Checked); // @violation
        }

    }
}