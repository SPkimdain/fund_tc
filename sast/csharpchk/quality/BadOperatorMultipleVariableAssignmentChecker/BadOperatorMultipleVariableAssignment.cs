using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        private static int x = 10, y;
        private int z = y = x;              // @violation

        public static void TestMethod(int i, int j)
        {
            int a, b;
            a = b = i;                      // @violation
            a = b = i = j;                  // @violation
            int c = a = b;                  // @violation
            b = i;                          // @safe
            a = i;                          // @safe
        }

        public static int TestMethod2(int a, int b)
        {
            return a + b;
        }

        static void Main(string[] args)
        {
            int i, j;
            TestMethod(2);
            i = j = TestMethod2(3, 4);      // @violation
        }
    }
}
