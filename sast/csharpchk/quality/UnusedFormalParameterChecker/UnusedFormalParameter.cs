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
        public static int TestMethod(int a, int b, int c)// @violation
        {
            return a+c;
        }
        static void Main(string[] args)// @violation
        {
            int a = 1;
            int b = 2;
            int c = 3;
            int i = TestMethod(a,b,c);

        }
        protected void Page_Load(
        ) {

        }
    }
    class WebForms
    {
        protected void Page_Load(object sender, EventArgs e) //@sound
        {
            if(Page.IsPostBack)
                return;

            if(!string.IsNullOrEmpty(Request.QueryString["SearchTerm"]))
            {
                // do something
            }
        }

    }
}
