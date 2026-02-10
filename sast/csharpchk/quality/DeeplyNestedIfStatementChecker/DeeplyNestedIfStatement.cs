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
        public int getItem()
        {
            return f;
        }
        public void setItem(int i)
        {
            this.f = i;
        }
    }
    class Program
    {
        public static void TestMethod()
        {
            Foo tmp = new Foo(0);
            if (tmp.getItem() != 1)
            {
                if (tmp.getItem() != 2)
                {
                    if (tmp.getItem() != 3)
                    {
                        if (tmp.getItem() != 4)         // @violation
                        {
                            if (tmp.getItem() != 5)     // @violation
                            {
                                tmp.setItem(6);
                            }
                        }
                    }
                }
            }
        }

        public static void TestMethod2()
        {
            Foo tmp = new Foo(1);
            if (tmp.getItem() != 1)
            {
                if (tmp.getItem() != 2)
                {
                    if (tmp.getItem() != 3)
                    {
                        tmp.setItem(4);
                    }
                }
            }
        }


        static void Main(string[] args)
        {
            TestMethod();
            TestMethod2();
        }
    }
}
