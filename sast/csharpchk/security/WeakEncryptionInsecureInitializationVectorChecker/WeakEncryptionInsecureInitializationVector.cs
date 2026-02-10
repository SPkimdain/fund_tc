using System.IO;
using System.Text;
using System.Security.Cryptography;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            byte[] key = {
                0x61, 0x62, 0x63, 0x64, 0x65, 0x65, 0x67, 0x68,
                0x61, 0x62, 0x63, 0x64, 0x65, 0x65, 0x67, 0x68,
                0x61, 0x62, 0x63, 0x64, 0x65, 0x65, 0x67, 0x68,
                0x61, 0x62, 0x63, 0x64, 0x65, 0x65, 0x67, 0x68,
            };
            byte[] IV = {
                0x61, 0x62, 0x63, 0x64, 0x65, 0x65, 0x67, 0x68,
                0x61, 0x62, 0x63, 0x64, 0x65, 0x65, 0x67, 0x68,
            };
            string s_IV = "1234567812345678";
            byte[] IV2 = Encoding.ASCII.GetBytes(s_IV);
            
            MemoryStream ciphertext = new MemoryStream();

            SymmetricAlgorithm rijn = SymmetricAlgorithm.Create();
            rijn.CreateEncryptor(key, IV); // @violation
            RNGCryptoServiceProvider rng = new RNGCryptoServiceProvider();
            rng.GetBytes(IV);
            rijn.IV = IV;
            rijn.IV = IV2; // @violation
            rijn.GenerateIV();

            CryptoStream encStream = new CryptoStream(ciphertext, rijn.CreateEncryptor(key, IV), CryptoStreamMode.Write);
        }
    }
}