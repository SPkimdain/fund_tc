using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Quality
{
    class Program
    {
        public static string TestMethod(String str)
        {
            return str + $"" + str;     // @violation
        }

        public static string TestMethod2(String str)
        {
            return str + str;
        }

        public static string TestMethod3(String str)
        {
            return "" + str;            // @violation
        }

        static void Main(string[] args)
        {
            String a = "a";
            String b, c;
            b = TestMethod(a);
            c = TestMethod2(b);
            b = TestMethod3(c);
        }
    }
}
