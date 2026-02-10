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
            Queue sample = new Queue();
            Monitor.Pulse(sample);          // @violation
            Monitor.PulseAll(sample);       // @safe
        }
    }
}
