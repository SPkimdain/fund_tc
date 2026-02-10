using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        public static bool TestMethod(String str)
        {
            if (str.Equals("a"))                // @violation
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public static bool TestMethod2(String str)
        {
            if ("b".Equals(str))
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        static void Main(string[] args)
        {
            String a = "a";
            if (TestMethod(a))
            {
                a = a + a;
                return;
            }
            else if(TestMethod(a))
            {
                return;
            }
        }

        public static bool TestMethod3(int a, int b)
        {
            int b = a.Equals(null) ? 1 : 2;     // @violation
        }
    }
}
