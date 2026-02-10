using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Security.Cryptography;

namespace ConsoleApplication1
{
    class Program 
    {
        static void Main(string[] args)
        {     
        }

        static string getMd5Hash(string input)
        {
            MD5CryptoServiceProvider md5Hasher = new MD5CryptoServiceProvider(); // @violation
        }

        static string getSHA1Hash(string input)
        {
            SHA1 sha = new SHA1CryptoServiceProvider(); // @violation
        }
    }
}
