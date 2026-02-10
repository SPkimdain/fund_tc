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
            Queue<int> q = new Queue<int>();
            List<int> l = new List<int>();
            for (int i = 0; i < 100; i++)
            {
                q.Enqueue(i);
                l.Add(i);
            }
            for (int i = 0; i < 100; i++)
            {
                if (q.Count() == 0)// @violation
                {
                    break;
                }
                else
                {
                    q.Dequeue();
                }
                if (l.Count() == 0)// @violation
                {
                    break;
                }
                else if (0 == l.Count())// @violation
                {
                    break;
                }
                else
                {
                    l.Remove(0);
                }
            }
        }
    }
}
