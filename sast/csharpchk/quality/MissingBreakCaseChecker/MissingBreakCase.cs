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
            switch (i)
            {
                case 1:// @violation
                    i++;
                    break;
                    i++;
                case 0:
                    i--;
                    break;
                case 2: {
                    i--;
                    break;
                }
                case 3:
                    return;
                case 4:  {
                    return;
                }
                default:
                    i = 10;
                    break;
            }
        }
        static void Main(string[] args)
        {
            TestMethod(2);
        }
    }
}
