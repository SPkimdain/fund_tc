using System;

namespace ConsoleApplication
{
    class MissingBlankLineBeforeComment
    {
        public static void BadCase1()
        {
            Console.WriteLine("BadCase1"); // uncorrected location // @violation
        }

        public static void BadCase2()
        {
            Console.WriteLine("BadCase2"); /* @violation
                                            * uncorrected location
                                            * uncorrected location





                                            * uncorrected location */
        }

        public static void GoodCase1()
        {
            // corrected location
            Console.WriteLine("GoodCase1");
        }

        public static void GoodCase2()
        {
            /// <summary>
            /// 입력 파라미터의 합을 반환합니다.
            /// </summary>
            Console.WriteLine("GoodCase2");
        }

        public static void GoodCase3()
        {
            /* corrected location
             * corrected location
             * corrected location
             * corrected location */
            Console.WriteLine("GoodCase3");
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