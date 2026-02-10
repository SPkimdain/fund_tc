using System;
using System.Text;
using System.Security.Cryptography;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            String password = "password";
            String s_salt = "!!@!@!@!@!#!@";
            int iteration = 50;
            int iteration2 = 20000;

            Rfc2898DeriveBytes rdb8 = new Rfc2898DeriveBytes(password, 8);
            rdb8.IterationCount = 1000; // @violation
            rdb8.IterationCount = 20000;

            Rfc2898DeriveBytes rdb32 = new Rfc2898DeriveBytes(password, Encoding.Default.GetBytes(s_salt), 1000); // @violation
        }
    }
}