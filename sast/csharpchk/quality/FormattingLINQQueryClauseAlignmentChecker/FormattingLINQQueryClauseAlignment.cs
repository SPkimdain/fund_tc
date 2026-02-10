using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpCheckerTest
{
    class FormattingLINQQueryClauseAlignment
    {
        public static void BadCase1()
        {
            int[] scores = new int[] { 97, 92, 81, 60 };

            IEnumerable<int> scoreQuery =
                from score in scores where score > 80 select score; // @violation

            Console.WriteLine("BadCase1");

            foreach(int i in scoreQuery)
            {
                Console.Write(i + " ");
            }
            Console.WriteLine();
        }

        public static void BadCase2()
        {
            int[] scores = new int[] { 97, 92, 81, 60 };

            IEnumerable<int> scoreQuery = from score in scores
                                          where score > 80 select score; // @violation

            Console.WriteLine("BadCase2");

            foreach(int i in scoreQuery)
            {
                Console.Write(i + " ");
            }
            Console.WriteLine();
        }

        public static void BadCase3()
        {
            int[] scores = new int[] { 97, 92, 81, 60 };

            IEnumerable<int> scoreQuery = from score in scores
                                        where                   // @violation
                                             score > 80
                                          select score;

            Console.WriteLine("BadCase2");

            foreach(int i in scoreQuery)
            {
                Console.Write(i + " ");
            }
            Console.WriteLine();
        }

        public static void GoodCase1()
        {
            int[] scores = new int[] { 97, 92, 81, 60 };

            IEnumerable<int> scoreQuery =
                from score in scores
                where score > 80
                select score;

            Console.WriteLine("GoodCase1");

            foreach (int i in scoreQuery)
            {
                Console.Write(i + " ");
            }
            Console.WriteLine();
        }

        public static void GoodCase2()
        {
            var q = from f in Foo
                    where f.FooID ==
                    (
                        from fb in FooBar
                        where fb.BarID == 1000
                        select fb.FooID
                    )
                    select f;
        }

        public static void print()
        {
            Console.WriteLine("*******************************************************");
            Console.WriteLine("* You should align query clauses under 'from' clauses *");
            Console.WriteLine("*******************************************************");
        }

        static void Main(string[] args)
        {
            BadCase1();
            BadCase2();
            BadCase3();
            GoodCase1();

            print();
        }
    }
}