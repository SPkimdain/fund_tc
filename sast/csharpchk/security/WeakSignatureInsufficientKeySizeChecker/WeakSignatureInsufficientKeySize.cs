using System.Security.Cryptography;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            useDES("Hello World");
        }

        static void useDES(string input)
        {
            DSA DSAalg_0 = new DSACryptoServiceProvider(512); // @violation
            DSA DSAalg_1 = new DSACryptoServiceProvider(1024); // @violation
            DSA DSAalg_2 = new DSACryptoServiceProvider(2048);

            return;
        }
    }
}