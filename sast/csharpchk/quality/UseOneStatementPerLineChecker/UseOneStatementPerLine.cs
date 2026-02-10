extern alias Test1; extern alias Test2; extern alias Test3; // @violation

using System; using System.Collections; // @violation

using System.Linq;
using System.Text.RegularExpressions;
using Raven.Abstractions.Indexing;
using Raven.Client;
using Raven.Client.Indexes;
using Raven.Tests.Common;

namespace ConsoleApplication
{
    class UseOneStatementPerLine
    {
        interface IEquatable<T>
        {
            bool Equals(T obj); bool NotEquals(T obj); // @violation
        }
        delegate void del(string s);
        private static string badCase3 = "badCase3"; private static string badCase4 = "badCase4";   // @violation

        public static void BadCase1()
        {
            Console.WriteLine("BadCase1 - 1"); Console.WriteLine("BadCase1 - 2");   // @violation
        }

        public static void BadCase3()
        {
            del badCaseDel = n => { string s = n + " " + "World"; Console.WriteLine(s); };  // @violation
            badCaseDel("Hello");
        }

        public static void GoodCase1()
        {
            Console.WriteLine("GoodCase1 - 1");
            Console.WriteLine("GoodCase1 - 2");
        }

        public static void GoodCase2()
        {
            Console.WriteLine("GoodCase2");
        }

        public static void GoodCase3()
        {
            del goodCaseDel = n => { string s = n + " " + "World";
                Console.WriteLine(s); };
            goodCaseDel("Hello");
        }

        public static void print()
        {
            Console.WriteLine("************************************************");
            Console.WriteLine("* You should write only one statement per line *");
            Console.WriteLine("************************************************");
        }

        public static void Main(string[] args)
        {
            BadCase1();
            BadCase2();
            BadCase3();
            GoodCase1();
            GoodCase2();
            GoodCase3();
        }
    }
}