using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Quality
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
        Boolean TestMethod(Double a, Double b)
        {
            return a == b;      // @violation
        }
        static void Main(string[] args)
        {
            float x;
            float y;
            x = 2.0F;
            y = 3.0F;
            if (x == y)         // @violation
            {
                return;
            }

            int a = 1;
            int b = 2;

            if (a == b)         // @safe
            {

            }
        }
    }
}
