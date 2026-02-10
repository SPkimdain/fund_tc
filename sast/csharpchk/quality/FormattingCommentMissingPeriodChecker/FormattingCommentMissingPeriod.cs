using System;

namespace ConsoleApplication
{
    class FormattingCommentMissingPeriod
    {
        public static void BadCase1()
        {
            // BadCase1
            // test
            // test
            // test // @violation
            Console.WriteLine("BadCase1");
        }

        /// <summary cref="C &lt; T &gt;">
        /// test    // @violation
        /// </summary>
        public static void BadCase2()
        {
            /* @violation
             * BadCase2
             * BadCase2
             * BadCase2 */
            Console.WriteLine("BadCase2");
        }

        /// <summary>
        /// This is meta test used for route analysis, when there is route for system db and route for non-system db is not present (or vice versa),
        /// then if controller is not present on ignore list throw an exception.
        /// </summary>

        public static void GoodCase1()
        {
            // GoodCase1.
            Console.WriteLine("GoodCase1");
        }

        public static void GoodCase2()
        {
            /* GoodCase2.
             * GoodCase2.
             * GoodCase2. */
            Console.WriteLine("GoodCase2");
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