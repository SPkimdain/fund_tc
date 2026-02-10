using System;

namespace ConsoleApplication
{
    class FormattingContinuationLineBadIndentation
    {

        static readonly Dictionary<string, string> LuaTypeNameReplacements = new Dictionary<string, string>()
        {
            { "Void", "void" },
            { "Int32", "int" },
            { "String", "string" },
            { "Boolean", "bool" }
        };

        private string badString1 = "BadString1"    // @violation
        + " In Field Variable";

        private const string badString2 = "BadString2"  // @violation
        + " In Constant Field Variable";

        public static void BadCase1()
        {
            if(20 > 10  // @violation
            && 30 > 10)
            {
                Console.WriteLine("BadCase1_1");
            }

            while(20 > 10   // @violation
            && 30 > 10)
            {
                Console.WriteLine("BadCase1_2");
                break;
            }
        }

        public static void BadCase2()
        {
            string badCase2 = "BadCase2"    // @violation
            + " string declaration";

            Console.WriteLine(badCase2      // @violation
            + " In Method Parameter"
            + " And multi lines");
        }

        public static void GoodCase1()
        {
            if(20 > 10
                && 30 > 10)
            {
                Console.WriteLine("GoodCase1_1");
            }

            while(20> 10
                && 30 > 10)
            {
                Console.WriteLine("GoodCase1_2");
                break;
            }
        }

        public static void GoodCase2()
        {
            string goodCase2 = "GoodCase2"
                + " string declaration";

            Console.WriteLine(goodCase2
                + " In Method Parameter"
                + " And multi lines");
        }

        private static void print()
        {
            Console.WriteLine("****************************************");
            Console.WriteLine("* You do not indent continuation lines *");
            Console.WriteLine("****************************************");
        }

        public static void Main(string[] args)
        {
            BadCase1();
            BadCase2();
            GoodCase1();
            GoodCase2();
        }
    }
}