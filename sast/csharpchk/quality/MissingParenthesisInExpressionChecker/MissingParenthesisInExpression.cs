using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;

namespace CSharpCheckerTest
{
    class MissingParenthesisInExpression
    {
        public static void BadCase1()
        {
            int val1 = 30;
            int val2 = 20;
            int val3 = 10;

            if (val1 > val2 && val1 > val3)             // @violation
            {
                Console.WriteLine("BadCase1");
            }
        }

        public static void BadCase2()
        {
            int val1 = 30;
            int val2 = 20;
            int val3 = 10;

            if ((val1 > val2 && val1 > val3))           // @violation
            {
                Console.WriteLine("BadCase2");
            }
        }

        public static void BadCase3()
        {
            int val1 = 30;
            int val2 = 20;
            int val3 = 10;

            if ((val1 > val2) && val1 > val3)           // @violation
            {
                Console.WriteLine("BadCase3");
            }
        }

        public static void BadCase4()
        {
            int val1 = 30;
            int val2 = 20;
            int val3 = 10;

            if (val1 > (val2 + val3) && (val1 > val3))  // @violation
            {
                Console.WriteLine("BadCase4");
            }
        }

        public static void GoodCase1()
        {
            int val1 = 30;
            int val2 = 20;
            int val3 = 10;

            if ((val1 > val2) && (val1 > val3))
            {
                Console.WriteLine("GoodCase1");
            }
        }

        public static void GoodCase2()
        {
            int val1 = 30;
            int val2 = 20;
            int val3 = 10;

            if ((val1 > (val2 + val3)) && (val1 > val3))
            {
                Console.WriteLine("GoodCase2");
            }
        }

        public static void GoodCase3()
        {
            int val1 = 30;
            int val2 = 20;
            int val3 = 10;

            if (isTrue() && (val1 > val3))
            {
                Console.WriteLine("GoodCase3");
            }
        }

        public static void GoodCase4()
        {
            int val1 = 30;
            int val2 = 20;
            int val3 = 10;

            if (true && (val1 > val3))
            {
                Console.WriteLine("GoodCase4");
            }
        }

        public static void print()
        {
            Console.WriteLine("***********************************************************");
            Console.WriteLine("* You should make expression clauses by using parentheses *");
            Console.WriteLine("***********************************************************");
        }

        public float TextureMidIndex { get { return (index + 0.5f) / hardwarePalette.Height; } }

        static void Main(string[] args)
        {
            BadCase1();
            GoodCase1();

            print();
        }
    }
}