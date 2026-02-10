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
            string key = "1234567890123456"; // key size should be 16 byte in current setting(128 bit)

            byte[] toEncryptArray = UTF8Encoding.UTF8.GetBytes(toEncrypt);
            keyArray = UTF8Encoding.UTF8.GetBytes(key);

            TripleDESCryptoServiceProvider tdes = new TripleDESCryptoServiceProvider();
            //set the secret key for the tripleDES algorithm
            tdes.Key = keyArray;
            //mode of operation. there are other 4 modes. We choose ECB(Electronic code Book)
            tdes.Mode = CipherMode.ECB; // @violation
            //padding mode(if any extra byte added)
            tdes.Padding = PaddingMode.PKCS7;

            ICryptoTransform cTransform = tdes.CreateEncryptor();
            //transform the specified region of bytes array to resultArray
            byte[] resultArray = cTransform.TransformFinalBlock
                    (toEncryptArray, 0, toEncryptArray.Length);
            //Release resources held by TripleDes Encryptor
            tdes.Clear();
            //Return the encrypted data into unreadable string format
            return Convert.ToBase64String(resultArray, 0, resultArray.Length);
        }
    }
}