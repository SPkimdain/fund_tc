/* WITH_CHECKERS : HARD_CODED_CRYPTOGRAPHIC_KEY_CSHARP */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Security.Cryptography;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
namespace NewNonghyupCheckers
{
    class HardCodedCryptographicKey
    {
        public static void EncryptTextToFile(String data, String fileName)
        {
            try
            {
                byte[] key = new byte[] { 0x43, 0x87, 0x23, 0x72 };
                byte[] iv = new byte[] { 0x43, 0x87, 0x23, 0x72 };
                FileStream fStream = File.Open(fileName, FileMode.OpenOrCreate);

                CryptoStream cStream = new CryptoStream(fStream,
                    new TripleDESCryptoServiceProvider().CreateEncryptor(key, iv), /* BUG: HARD_CODED_CRYPTOGRAPHIC_KEY_CSHARP */
                    CryptoStreamMode.Write);

                StreamWriter sWriter = new StreamWriter(cStream);

                sWriter.WriteLine(data);

                sWriter.Close();
                cStream.Close();
                fStream.Close();
            }
            catch (CryptographicException e)
            {
                Console.WriteLine("Error");
            }
            catch (UnauthorizedAccessException e)
            {
                Console.WriteLine("Error");
            }
        }

        public static void EncryptTextToFileGood(String data, String fileName)
        {
            try
            {
                FileStream fStream = File.Open(fileName, FileMode.OpenOrCreate);

                TripleDESCryptoServiceProvider desCSP = new TripleDESCryptoServiceProvider();
                desCSP.GenerateKey();
                desCSP.GenerateIV();

                CryptoStream cStream = new CryptoStream(fStream,
                    descCSP.CreateEncryptor(), // NOT BUG
                    CryptoStreamMode.Write);

                StreamWriter sWriter = new StreamWriter(cStream);

                sWriter.WriteLine(data);

                sWriter.Close();
                cStream.Close();
                fStream.Close();
            }
            catch (CryptographicException e)
            {
                Console.WriteLine("Error");
            }
            catch (UnauthorizedAccessException e)
            {
                Console.WriteLine("Error");
            }
        }
    }
}
