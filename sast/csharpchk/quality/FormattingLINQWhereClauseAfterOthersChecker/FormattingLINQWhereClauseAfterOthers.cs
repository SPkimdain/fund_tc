using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpCheckerTest
{
    class FormattingLINQWhereClauseAfterOthers
    {
        public static void BadCase1()
        {
            int[] scores = new int[] { 97, 92, 81, 60 };

            IEnumerable<int> scoreQuery =
                from score in scores
                orderby score
                where score > 80    // @violation
                select score;

            Console.WriteLine("GoodCase1");

            foreach (int i in scoreQuery)
            {
                Console.Write(i + " ");
            }
            Console.WriteLine();
        }

        public static void BadCase2()
        {
            var q = from f in Foo
                    where f.FooID ==
                    (
                        from fb in FooBar
                        orderby fb.BarID
                        where fb.BarID == 1000  // @violation
                        select fb.FooID
                    )
                    select f;
        }

        public static void GoodCase1()
        {
            int[] scores = new int[] { 97, 92, 81, 60 };

            IEnumerable<int> scoreQuery =
                from score in scores
                where score > 80
                orderby score
                select score;

            Console.WriteLine("GoodCase1");

            foreach (int i in scoreQuery)
            {
                Console.Write(i + " ");
            }
            Console.WriteLine();
        }

        public static void print()
        {
            Console.WriteLine("*************************************************************");
            Console.WriteLine("* You should use 'where' clauses before other query clauses *");
            Console.WriteLine("* to ensure that later query clauses operate on the reduced *");
            Console.WriteLine("*                   filtered set of data                    *");
            Console.WriteLine("*************************************************************");
        }

        static void Main(string[] args)
        {
            BadCase1();
            GoodCase1();

            print();
        }
    }
}