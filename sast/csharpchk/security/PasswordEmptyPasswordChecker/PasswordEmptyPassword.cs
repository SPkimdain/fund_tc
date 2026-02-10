using System;
using System.Net;
using System.Security;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            string UserName = "username";
            string Password = "password";
            string null_Pass = "";

            NetworkCredential myCred = new NetworkCredential(UserName, ""); // @violation
            NetworkCredential vuln_myCred = new NetworkCredential(UserName, null_Pass); // @violation
            NetworkCredential secure_myCred = new NetworkCredential(UserName, Password);

            myCred.Password = Password;
            vuln_myCred.Password = null_Pass; // @violation
            CredentialCache myCache = new CredentialCache();

            myCache.Add(new Uri("http://www.contoso.com"), "Basic", myCred);
            myCache.Add(new Uri("http://app.contoso.com"), "Basic", myCred);

            WebRequest wr = WebRequest.Create("http://www.contoso.com");
            wr.Credentials = myCache;
        }
    }
}