using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Web;

namespace newFeatures
{
    namespace PatternDecl
    {
        class Program : System.Web.UI.Page
        {
            protected void Page_Load(object sender, EventArgs e)
            {
                test(MessageTextBox.Text); /* BUG: HTTP_RESPONSE_SPLITTING_ASPNET */
                test2(MessageTextBox.Text);
            }

            public void test(object x)
            {
                switch(x)
                {
                    case 0:
                    case 1:
                        Console.WriteLine("test1");
                        break;
                    case 2 when x.ToString() == "2":
                        Console.WriteLine("test2");
                        break;
                    case int z when z < 10:
                        Console.WriteLine("test3" + z);
                        break;
                    case int z when z >= 10:
                        Console.WriteLine($"test3 {z}");
                        break;
                    case string s when Label1.Text.Length > 0   :
                        Response.AddHeader("Test", "Hi, " + s);
                        break;
                    default:
                        return;
                }
            }

            public void test2(object x)
            {
                if (x is string k)
                {
                    Console.WriteLine(k);
                }
                else if (x is int z)
                {
                    Console.WriteLine("x is int z");
                }
                else if (x is string s && s != "")
                {
                    Console.WriteLine($@"testing... {{ {s} }} ""quote"" ");
                }
            }
        }
    }
}
