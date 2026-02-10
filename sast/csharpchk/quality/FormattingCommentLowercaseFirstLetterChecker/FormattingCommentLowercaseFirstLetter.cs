using System;

namespace ConsoleApplication
{
    class FormattingCommentLowercaseFirstLetter
    {
        public static void BadCase1()
        {
            Console.WriteLine("BadCase1");  // badCase1 // @violation
        }

        public static void BadCase2()
        {
            Console.WriteLine("BadCase2");  /* @violation
                                             * badCase2
                                             * badCase2
                                             * badCase2 */
        }

        public static void GoodCase1()
        {
            Console.WriteLine("GoodCase1"); // GoodCase1
        }

        public static void GoodCase2()
        {
            Console.WriteLine("GoodCase2"); /* GoodCase2
                                             * GoodCase2
                                             * GoodCase2
                                             * GoodCase2 */
        }
        public static void GoodCase3()
        {
            Console.WriteLine("GoodCase3"); // _'129852'goodCase3
        }

        public static void Main(string[] args)
        {
            BadCase1();
            BadCase2();
            GoodCase1();
            GoodCase2();
            GoodCase3();
        }
    }
}