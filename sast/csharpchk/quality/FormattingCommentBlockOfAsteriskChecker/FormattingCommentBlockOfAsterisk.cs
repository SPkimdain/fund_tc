using System;

namespace ConsoleApplication
{
    class FormattingCommentBlockOfAsterisk
    {
        public static void BadCase1()
        {
            /* @violation
             * BadCase1
             * BadCase1 */
            Console.WriteLine("BadCase1");
        }

        public static void BadCase2()
        {
            /* @violation
               BadCase2
               BadCase2
             * BadCase2 */
            Console.WriteLine("BadCase2");
        }

        public static void GoodCase1()
        {
            /* GoodCase1
               GoodCase1
               GoodCase1 */
            Console.WriteLine("GoodCase1");
        }

        public static void Main(string[] args)
        {
            BadCase1();
            BadCase2();
            GoodCase1();
        }
    }
}