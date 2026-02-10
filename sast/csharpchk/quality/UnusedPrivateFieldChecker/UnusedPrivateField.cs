using System;
using System.Threading;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    public class Foo
    {
        int f;
        double d;
        private string p;// @violation
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
        private int unused_i;// @violation
        public static int TestMethod(int a, int b, int c)
        {
            return a+b+c;
        }
        static void Main(string[] args)
        {
            int a = 1;
            int b = 2;
            int c = 3;
            int i = TestMethod(a,b,c);

        }
    }
}
