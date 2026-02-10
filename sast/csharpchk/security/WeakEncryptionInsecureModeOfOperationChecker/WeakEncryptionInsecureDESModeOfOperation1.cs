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

            DESCryptoServiceProvider des = new DESCryptoServiceProvider();
            des.Key = keyArray;
            des.Mode = CipherMode.ECB; // @violation
            des.Padding = PaddingMode.PKCS7;

            ICryptoTransform cTransform = des.CreateEncryptor();
            byte[] resultArray = cTransform.TransformFinalBlock
                    (toEncryptArray, 0, toEncryptArray.Length);
            des.Clear();
            return Convert.ToBase64String(resultArray, 0, resultArray.Length);
        }
    }
}