using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Web;

namespace newFeatures
{
    namespace TupleTest
    {
        class TupleTestClass : System.Web.UI.Page
        {
            public (string, int, string) tupleCreator1(string x, int y, string z)
            {
                return (x, y, z);
            }

            public (string a, int b, string c) tupleCreator2(string x, int y)
            {
                return (x, y, y.ToString());
            }

            protected void Page_Load(object sender, EventArgs e)
            {
                var tuple1 = ("a", 2, MessageTextBox.Text);
                var (simpleDeconstr1, simpleDeconstr2, simpleDeconstr3) = tuple1;

                Response.AddHeader("Test", "Hi, " + simpleDeconstr3); /* BUG: HTTP_RESPONSE_SPLITTING_ASPNET */

                var (methodDeconstr1, methodDeconstr2, methodDeconstr3) = tupleCreator1(MessageTextBox.Text, 4, "f");

                Response.AddHeader("Test", "Hi, " + methodDeconstr1); /* BUG: HTTP_RESPONSE_SPLITTING_ASPNET */

                var (methodDeconstr4, methodDeconstr5, methodDeconstr6) = tupleCreator2(MessageTextBox.Text, 7);

                Response.AddHeader("Test", "Hi, " + methodDeconstr6); // Not bug

                var tuple2 = tupleCreator2(MessageTextBox.Text, 9);

                string mem1 = tuple2.a;
                int mem2 = tuple2.b;
                string mem3 = tuple2.c;

                Response.AddHeader("Test", "Hi, " + mem3); // Not bug

                (string mem4, int mem5, string mem6) = tuple2;

                Response.AddHeader("Test", "Hi, " + mem4); /* BUG: HTTP_RESPONSE_SPLITTING_ASPNET */

                if (tuple1 == tuple2) {
                    Console.Write("equals~~");
                }

                CanBeDestructed destObj1 = new CanBeDestructed(MessageTextBox.Text);
                var (mem7, mem8) = destObj1;
                Response.AddHeader("Test", "Hi, " + mem8); /* BUG: HTTP_RESPONSE_SPLITTING_ASPNET */
                (mem7, mem8) = destObj1; // reassign test

                MayBeDestructed destObj2 = new MayBeDestructed(MessageTextBox.Text);
                var (mem9, mem10) = destObj2;
                Response.AddHeader("Test", "Hi, " + mem10); /* BUG: HTTP_RESPONSE_SPLITTING_ASPNET */

                var right_tuple = tupleCreator1(MessageTextBox.Text, 4, "f");
                var left_tuple = tupleCreator2("clean", 10);
                left_tuple = right_tuple;
                Response.AddHeader("Test", "Hi, " + left_tuple.a); /* BUG: HTTP_RESPONSE_SPLITTING_ASPNET */
            }
        }

        static class MayBeDestructedExtension
        {
            public static void Deconstruct(this MayBeDestructed o, out int x, out string y)
            {
                x = o.m;
                y = o.n;
            }
        }

        class CanBeDestructed
        {
            private string field;
            public CanBeDestructed(string x)
            {
                field = x;
            }
            public void Deconstruct(out int a, out string b)
            {
                a = 1;
                b = field;
            }
        }

        class MayBeDestructed
        {
            public int m = 0;
            public string n = "zero";

            public MayBeDestructed(string x)
            {
                n = x;
            }
        }
    }
}
