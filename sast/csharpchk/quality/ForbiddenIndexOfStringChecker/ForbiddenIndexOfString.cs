using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    public class Foo
    {
        int f;
        double d;
        public Foo(int i, double d)
        {
            this.f = i;
            this.d = d;
        }
        public int getInt()
        {
            return this.f;
        }
        public double getDouble()
        {
            return this.d;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            string str = "abc";
            if (str.IndexOf("a") == 0)          // @violation
            {
                return;
            }
            else if (str.IndexOf('a') == 0)     // @safe
            {
                return;
            }
        }
    }
}
