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
            byte[] password_b = Encoding.Default.GetBytes(password);
            String s_salt = "!!@!@!@!@!#!@";

            Rfc2898DeriveBytes rdb8 = new Rfc2898DeriveBytes("", 10001); // @violation
            Rfc2898DeriveBytes rdb16 = new Rfc2898DeriveBytes(password, Encoding.Default.GetBytes(s_salt), 10001);
        }
    }
}