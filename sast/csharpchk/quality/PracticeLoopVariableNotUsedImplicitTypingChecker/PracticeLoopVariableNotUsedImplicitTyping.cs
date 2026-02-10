using System;
namespace ConsoleApplication
{
    class PracticeLoopVariableNotUsedImplicitTyping
    {
        public static void BadCase1()
        {
            var syllable = "ha";
            var laugh = "";

            Console.WriteLine("BadCase1-1 :");

            for (int i = 0; i < 10; i++)    // @violation
            {
                laugh += syllable;
                Console.WriteLine(laugh);
            }

            Console.WriteLine("BadCase1-2 :");

            foreach(char ch in laugh)   // @violation
            {
                if (ch == 'h')
                    Console.Write("H");
                else
                    Console.Write(ch);
            }
            Console.WriteLine();
        }

        public static void GoodCase1()
        {
            var syllable = "ha";
            var laugh = "";

            Console.WriteLine("GoodCase1-1 :");

            for (var i = 0; i < 10; i++)
            {
                laugh += syllable;
                Console.WriteLine(laugh);
            }

            Console.WriteLine("GoodCase1-2 :");

            foreach (var ch in laugh)
            {
                if (ch == 'h')
                    Console.Write("H");
                else
                    Console.Write(ch);
            }
            Console.WriteLine();
        }

        public static void print()
        {
            Console.WriteLine("***********************************************************");
            Console.WriteLine("*       You should use implicit typing to determine       *");
            Console.WriteLine("* the type of the loop variable in for and foreach loops. *");
            Console.WriteLine("***********************************************************");
        }

        public static void Main(string[] args)
        {
            BadCase1();
            Console.WriteLine("------------------------------------------");
            GoodCase1();
            Console.WriteLine("------------------------------------------");
            print();
        }
    }
}