/* WITH_CHECKERS : CLEAR_TEXT_TRANSMISSION_OF_SENSITIVE_INFORMATION_ASPNET */

using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.Mail;
using System.Web.UI;
using System.Web.UI.WebControls;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
namespace MyVulnerableWebsite
{
    public partial class ClearTextTransmission : System.Web.UI.Page
    {
        MembershipUser u;
        TextBox Msg;

        protected void Page_Load(object sender, EventArgs e)
        {
            u = Membership.GetUser(UsernameTextBox.Text, false);
            String password;

            if (u != null)
            {
                BadCase(u);
            }
            else
            {
                Msg.Text = "User name is invalid.";
            }
        }

        public void BadCase(MembershipUser user)
        {
            String password;
            try
            {
                password = user.GetPassword(); // sensitive data created
            }
            catch (Exception e)
            {
                Msg.Text = "An exception occurred retrieving your password: " + HttpUtility.HtmlEncode(e.Message);
                return;
            }
            MailMessage Message = new MailMessage();
            Message.Body = "Your password is: " + HttpUtility.HtmlEncode(password); // propagated
            SmtpMail.Send(Message); /* BUG: CLEAR_TEXT_TRANSMISSION_OF_SENSITIVE_INFORMATION_ASPNET */
            Msg.Text = "Password sent via e-mail";
        }

        public void GoodCase(MembershipUser user)
        {
            String password;
            try
            {
                password = user.GetPassword(); // sensitive data created
            }
            catch (Exception e)
            {
                Msg.Text = "An exception occurred retrieving your password: " + HttpUtility.HtmlEncode(e.Message);
                return;
            }
            MailMessage Message = new MailMessage();
            byte[] data = Encoding.ASCII.GetBytes(password);
            data = new Security.Cryptography.SHA256Managed().ComputeHash(data);
            string processedPassword = Encoding.ASCII.GetString(data);
            Message.Body = "Your password is: " + HttpUtility.HtmlEncode(processedPassword); // propagated
            SmtpMail.Send(Message); // not bug
            Msg.Text = "Password sent via e-mail";
        }
    }
}