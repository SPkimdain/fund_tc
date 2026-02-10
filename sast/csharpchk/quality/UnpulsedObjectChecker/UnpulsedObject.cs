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
        Queue<int> q;
        public Foo(int i, double d)
        {
            this.f = i;
            this.d = d;
            q = new Queue<int>();
        }
        public int getInt()
        {
            Monitor.PulseAll(q);
            return this.f;
        }
        public double getDouble()
        {
            Monitor.Wait(q);
            return this.d;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Queue<int> q = new Queue<int>();
            Monitor.PulseAll(q);// @violation
        }
    }
}
