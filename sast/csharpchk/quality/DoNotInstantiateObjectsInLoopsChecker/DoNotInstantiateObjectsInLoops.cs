using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Foo
    {
        int f;
        public Foo(int i)
        {
            this.f = i;
        }
    }

    class Program
    {
        public static void TestMethod()
        {
            for (int i = 0; i < 10; i++)
            {
                Foo tmp = new Foo(i);   // @violation
            }           
        }

        public static void TestMethod2()
        {
            Foo tmp = new Foo(1);
        }

        public static void TestMethod3()
        {
            int i = 0;
            while (i < 10)
            {
                Foo tmp = new Foo(i);   // @violation
                i++;
            }
        }
   
        static void Main(string[] args)
        {
            TestMethod();
            TestMethod2();
            TestMethod3();
        }
    }
}
