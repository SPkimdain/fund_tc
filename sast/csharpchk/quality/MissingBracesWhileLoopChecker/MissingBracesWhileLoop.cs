using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        public static void TestMethod()
        {
            int i = 0;
            while (i < 10)          // @violation
                i++;

            while (i < 10) {        // @safe
                i++;
            }
        }
        static void Main(string[] args)
        {
            TestMethod();
        }
    }
}
