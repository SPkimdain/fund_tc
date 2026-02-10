using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Windows.Forms;
using System.Threading;

namespace WindowsFormsApplication2
{
    public class Foo
    {
        int f;
        double d;
        public Foo(int i,double d)
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
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Foo tmp = new Foo(1, 0.5);
            if (tmp.getInt() == 0)
            {
                Application.Exit();// @violation
            }
        }
    }
}
