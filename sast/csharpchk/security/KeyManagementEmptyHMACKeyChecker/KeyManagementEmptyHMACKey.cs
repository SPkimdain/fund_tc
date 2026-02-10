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
            string input = "Testcode";

            HMACSHA512 sha512 = new HMACSHA512(key);
            byte[] byteArray = Encoding.ASCII.GetBytes(input);
            MemoryStream stream = new MemoryStream(byteArray);
            sha512.ComputeHash(stream);

            using (HMAC hmac = HMAC.Create("HMACSHA1"))
            {
                string hmacKey = "";
                byte[] keyBytes = Encoding.ASCII.GetBytes(hmacKey);
                byte[] keyBytes2 = {};
                byte[] inputBytes = Encoding.ASCII.GetBytes("Plaintext");
                hmac.Key = keyBytes; // @violation
                hmac.Key = keyBytes2; // @violation
                stream = new MemoryStream(inputBytes);
                hmac.ComputeHash(stream);
            }
            return;
        }
    }
}