/* WITH_CHECKERS : EXPOSURE_OF_SYSTEM_DATA_ASPNET */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.IO;
using System.Web.UI.WebControls;
using System.Security.Cryptography;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
namespace MyVulnerableWebsite
{
    public partial class ExposureOfSystemData : System.Web.UI.Page
    {
        String fileName;

        protected void Page_Load(object sender, EventArgs e)
        {
            if (Request.Cookies["data"] != null)
            {
                HttpCookie cookie = Request.Cookies["data"];
                try
                {
                    FileStream fStream = File.Open(fileName, FileMode.OpenOrCreate);

                    TripleDESCryptoServiceProvider desCSP = new TripleDESCryptoServiceProvider();
                    desCSP.GenerateKey();
                    desCSP.GenerateIV();

                    CryptoStream cStream = new CryptoStream(fStream,
                        desCSP.CreateEncryptor(),
                        CryptoStreamMode.Write);

                    StreamWriter sWriter = new StreamWriter(cStream);

                    sWriter.WriteLine(cookie.ToString());
                    Console.WriteLine(cookie.ToString()); /* BUG: EXPOSURE_OF_SYSTEM_DATA_ASPNET */

                    sWriter.Close();
                    cStream.Close();
                    fStream.Close();
                }
                catch (UnauthorizedAccessException e)
                {
                    Console.WriteLine("Error"); // not bug
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.ToString()); /* TODO: EXPOSURE_OF_SYSTEM_DATA_ASPNET is not found... improve exception analysis */
                }

            }
        }
    }
}