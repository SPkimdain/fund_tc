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

        static string useDES(string input)
        {
            CspParameters cspParams = new CspParameters();
            cspParams.KeyContainerName = "hi";

            RSACryptoServiceProvider RSAalg_0 = new RSACryptoServiceProvider(512); // @violation
            RSACryptoServiceProvider RSAalg_1 = new RSACryptoServiceProvider(1024); // @violation
            RSACryptoServiceProvider RSAalg_2 = new RSACryptoServiceProvider(2048);

            RSACryptoServiceProvider RSAalg_3 = new RSACryptoServiceProvider();
            RSACryptoServiceProvider RSAalg_4 = new RSACryptoServiceProvider(512, cspParams); // @violation
            RSACryptoServiceProvider RSAalg_5 = new RSACryptoServiceProvider(1024, cspParams); // @violation
            RSACryptoServiceProvider RSAalg_6 = new RSACryptoServiceProvider(2048, cspParams);

            return null;
        }
    }
}
