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
            for(int i=0;i<10 ;i++)      // @violation
                i++;

            for(int i=0;i<10 ;i++) {    // @safe
                i++;
            }
        }
        static void Main(string[] args)
        {
            TestMethod();
        }
    }
}
