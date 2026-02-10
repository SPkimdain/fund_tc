/* WITH_CHECKERS : SERVER_SIDE_REQUEST_FORGERY_CSHARP */

using System.Linq;
using System.IO;
using System.Net;
using System;

namespace CSharp
{
    public class ViolationClass
    {
        public static void Main(string[] args)
        {
            string url = args[0];

            WebRequest request = WebRequest.Create(url);                            /* BUG: SERVER_SIDE_REQUEST_FORGERY_CSHARP */
            request.Credentials = CredentialCache.DefaultCredentials;

            WebResponse response = request.GetResponse();
            Console.WriteLine(((HttpWebResponse)response).StatusDescription);

            using (Stream dataStream = response.GetResponseStream())
            {
                StreamReader reader = new StreamReader(dataStream);
                string responseFromServer = reader.ReadToEnd();
                Console.WriteLine(responseFromServer);
                reader.Close();
            }
            
            response.Close();
        }
    }

    public class GoodClass
    {
        private static readonly string[] whiteList = { "https://www.example.com" };

        public static void Main(string[] args)
        {
            string url = args[0];

            if (whiteList.Contains(url))
            {
                WebRequest request = WebRequest.Create(url);                            // good
                request.Credentials = CredentialCache.DefaultCredentials;

                WebResponse response = request.GetResponse();
                Console.WriteLine(((HttpWebResponse)response).StatusDescription);

                using (Stream dataStream = response.GetResponseStream())
                {
                    StreamReader reader = new StreamReader(dataStream);
                    string responseFromServer = reader.ReadToEnd();
                    Console.WriteLine(responseFromServer);
                    reader.Close();
                }

                response.Close();
            }
        }
    }
}
