using System.Text;
using System.Security.Cryptography;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            byte[] key = Encoding.ASCII.GetBytes("Hardcoded Key");
            byte[] key2 = {
                0x61, 0x62, 0x63, 0x64, 0x61, 0x62, 0x63, 0x64,
                0x61, 0x62, 0x63, 0x64, 0x61, 0x62, 0x63, 0x64};
            string input = "Testcode";

            HMACSHA512 sha512 = new HMACSHA512(key); // @violation
            HMACSHA1 sha1 = new HMACSHA1(key2); // @violation
            byte[] byteArray = Encoding.ASCII.GetBytes(input);
            MemoryStream stream = new MemoryStream(byteArray);
            sha512.ComputeHash(stream);
            sha1.ComputeHash(stream);

            using (HMAC hmac = HMAC.Create("HMACSHA1"))
            {
                string hmacKey = "";
                byte[] keyBytes = Encoding.ASCII.GetBytes(hmacKey);
                byte[] keyBytes2 = { };
                byte[] inputBytes = Encoding.ASCII.GetBytes("Plaintext");
                hmac.Key = keyBytes;
                hmac.Key = keyBytes2;
                stream = new MemoryStream(inputBytes);
                hmac.ComputeHash(stream);
            }
            return;
        }
    }
}