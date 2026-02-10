/* WITH_CHECKERS : PASSWORD_SAVED_WITHOUT_ENCRYPTION_ASPNET */

using System;
using System.IO;
using System.Text;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.Security;
using System.Security.Cryptography;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
namespace MyVulnerableWebsite
{
    public class FindPassword : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            var userId = "tmp";
            MembershipUser user = Membership.GetUser(userId);
            if (user != null)
            {
                var password = user.GetPassword();
                Response.Write(password); /* BUG: PASSWORD_SAVED_WITHOUT_ENCRYPTION_ASPNET */

                using (FileStream fs = new FileStream("pss.wd", FileMode.OpenOrCreate))
                {
                    byte[] fileData = Encoding.UTF8.GetBytes(password);
                    fs.Write(fileData, 0, fileData.Length); /* BUG: PASSWORD_SAVED_WITHOUT_ENCRYPTION_ASPNET */
                }

                using (FileStream fs = new FileStream("pss.wd", FileMode.OpenOrCreate))
                {
                    byte[] bytes = Encoding.UTF8.GetBytes(password);
                    byte[] hashed = new SHA256Managed().ComputeHash(bytes);
                    fs.Write(hashed, 0, hashed.Length); /* Safe */
                }
            }
            else
            {
                Response.Write("the given userId is not valid");
            }
        }
    }
}