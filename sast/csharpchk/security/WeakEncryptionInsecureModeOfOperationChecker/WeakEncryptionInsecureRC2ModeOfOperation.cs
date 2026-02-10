using System;
using System.Text;
using System.Security.Cryptography;
using System.Configuration;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            String password = "password";
            Encrypt(password);
        }

        public static string Encrypt(string toEncrypt)
        {
            byte[] keyArray;
            string key = "12345678"; // key size should be 8 byte in current setting(64 bit)

            byte[] toEncryptArray = UTF8Encoding.UTF8.GetBytes(toEncrypt);
            keyArray = UTF8Encoding.UTF8.GetBytes(key);

            RC2CryptoServiceProvider rc2 = new RC2CryptoServiceProvider();
            rc2.Key = keyArray;
            rc2.Mode = CipherMode.ECB; // @violation
            rc2.Padding = PaddingMode.PKCS7;

            ICryptoTransform cTransform = rc2.CreateEncryptor();
            byte[] resultArray = cTransform.TransformFinalBlock
                    (toEncryptArray, 0, toEncryptArray.Length);
            rc2.Clear();
            return Convert.ToBase64String(resultArray, 0, resultArray.Length);
        }
    }
}