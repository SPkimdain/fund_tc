using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        public static void TestMethod(int a)
        {
            int i, ret = 0;
            for (; ; )
            {
                i = 2;
                for (; ; )
                {
                    i++;
                    break;      // @violation
                }
                break;          // @violation
            }
            for(i=0; i<10; i++) {
                ret += i;
                if(ret > 30) {
                    break;
                }
            }
        }
        
        static void Main(string[] args)
        {
            TestMethod(2);
        }
    }
}
