using System;
using System.Collections;

namespace ConsoleApplication
{
    class UseOneDeclarationPerLine
    {
        public const string badCase2_1 = "BadCase2_1", badCase2_2 = "BadCase2_2";   // @violation
        private string a = "A", b = "B", c = "C";   // @violation

        public static void BadCase1()
        {
            int a = 1, b = 2, c = 3;    // @violation
            Console.WriteLine("BadCase1" + " " + a + " " + b + " " + c);
            print();
        }

        public static void BadCase3()
        {
            int a, b, c;        // @violation
            a = 1;
            b = 2;
            c = 3;
            Console.WriteLine("BadCase1" + " " + a + " " + b + " " + c);
            print();
        }

        public static void GoodCase1()
        {
            int a = 1;
            int b = 2;
            int c = 3;

            Console.WriteLine("GoodCase1" + " " + a + " " + b + " " + c);
        }

        private static void print()
        {
            Console.WriteLine("***************************************");
            Console.WriteLine("You write only one declaration per line");
            Console.WriteLine("***************************************");
        }

        public static void Main(string[] args)
        {
            BadCase1();
            GoodCase1();
        }
    }
}