using System;

namespace ConsoleApplication
{
    class FormattingCommentMissingSpaceAfterDelimiter
    {
        public static void BadCase1()
        {
            ///
            //BadCase1  // @violation
            Console.WriteLine("BadCase1");
        }

        public static void GoodCase1()
        {
            // GoodCase1
            Console.WriteLine("GoodCase1");
        }

        public static void Main(string[] args)
        {
            BadCase1();
            GoodCase1();
        }
    }
}