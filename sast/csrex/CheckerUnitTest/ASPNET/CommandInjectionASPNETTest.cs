/* WITH_CHECKERS : COMMAND_INJECTION_ASPNET */

using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
using System.Diagnostics;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Text.RegularExpressions;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
namespace MyVulnerableWebsite
{
    public class CommandInjection : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            BadCase(MessageTextBox);
            BadCase2(MessageTextBox);
            GoodCase(MessageTextBox);
            GoodCase2(MessageTextBox);
        }

        public void BadCase(TextBox box)
        {
            string fileName = box.Text;
            ProcessStartInfo info = new ProcessStartInfo();
            info.FileName = fileName;
            Process.Start(info); /* BUG: COMMAND_INJECTION_ASPNET */
        }

        public void BadCase2(TextBox box)
        {
            string fileName = box.Text;
            Process.Start(fileName); /* BUG: COMMAND_INJECTION_ASPNET */
        }

        public void GoodCase(TextBox box)
        {
            string fileName = box.Text;
            if (Regex.IsMatch(fileName, "[a-z0-9]+.pdf")) { // filter with validation logic
                ProcessStartInfo info = new ProcessStartInfo();
                info.FileName = fileName;
                Process.Start(info); // not bug
            }
        }

        public void GoodCase2(TextBox box)
        {
            string fileName = box.Text;
            if (Regex.IsMatch(fileName, "[a-z0-9]+.pdf")) { // filter with validation logic
                Process.Start(fileName); // not bug
            }
        }
    }
}