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
            int iteration = 50;

            Rfc2898DeriveBytes rdb8 = new Rfc2898DeriveBytes(password, 8);
            Rfc2898DeriveBytes rdb16 = new Rfc2898DeriveBytes(password, Encoding.Default.GetBytes(s_salt), iteration);
            Rfc2898DeriveBytes rdb32 = new Rfc2898DeriveBytes(password, Encoding.Default.GetBytes(password), iteration); // @violation
            Rfc2898DeriveBytes rdb64 = new Rfc2898DeriveBytes(password_b, password_b, iteration); // @violation

            // Below function is vulnerable. However, current checker cannot detect this function.
            // Further implementation using taint analysis would be needed.
            Rfc2898DeriveBytes rdb128 = new Rfc2898DeriveBytes(password, password_b, iteration);
        }
    }
}