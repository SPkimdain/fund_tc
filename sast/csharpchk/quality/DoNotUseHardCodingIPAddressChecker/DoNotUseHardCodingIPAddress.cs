using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        public static string TestMethod(String str)
        {
            return str + "192.168.0.1";             // @violation
        }
        [global::System.Gen("asdf", "4.0.0.0")]     // @safe
        public static string TestMethod2(String str)
        {
            return str + str;
        }

        public static string TestMethod3(String str)
        {
            return "255.300.141.45" + str;          // not ip address
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
