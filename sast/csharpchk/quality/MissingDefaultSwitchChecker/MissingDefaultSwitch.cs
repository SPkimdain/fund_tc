using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        public static void TestMethod(int i)
        {
            switch (i) { // @violation
                case 1:
                    i++;
                    break;
                case 0:
                    i--;
                    break;
            }
        }
        static void Main(string[] args)
        {
            TestMethod(2);
        }
    }
}
