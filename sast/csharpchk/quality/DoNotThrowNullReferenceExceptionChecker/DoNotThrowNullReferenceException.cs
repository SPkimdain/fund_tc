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
        public static int TestMethod(string str)
        {
            try
            {
                return str.Length;
            }
            catch
            {
                throw new NullReferenceException(); // @violation
            }
            NullReferenceException e = new NullReferenceException();
            throw e;                                // @violation
        }

        static void Main(string[] args)
        {
            string str = null ;
            try
            {
                int i = TestMethod(str);
            }
            catch
            {
                return;
            }
        }
    }
}
