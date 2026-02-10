using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpCheckerTest
{
    class PracticeLINQNotUsedImplicitTyping
    {
        public static void BadCase1()
        {
            int[] scores = new int[] { 97, 92, 81, 60 };

            IEnumerable<int> scoreQuery = from int score in scores  // @violation
                                   where score > 80
                                   select score;

            Console.WriteLine("BadCase1");

            foreach (int i in scoreQuery)
            {
                Console.Write(i + " ");
            }
            Console.WriteLine();
        }

        public static void BadCase2()
        {
            var ints1 = new int[] { 4, 3, 0 };
            var ints2 = new int[] { 5, 4, 2 };

            var result = from int t in ints1    // @violation
                         join int x in ints2 on (t + 1) equals x    // @violation
                         select t;

            Console.WriteLine("BadCase2");

            foreach(int r in result)
            {
                Console.Write(r + " ");
            }
            Console.WriteLine();
        }

        public static void GoodCase1()
        {
            int[] scores = new int[] { 97, 92, 81, 60 };

            IEnumerable<int> scoreQuery = from score in scores
                                          where score > 80
                                          select score;

            Console.WriteLine("GoodCase1");

            foreach(int i in scoreQuery)
            {
                Console.Write(i + " ");
            }
            Console.WriteLine();
        }

        public static void GoodCase2()
        {
            var ints1 = new int[] { 4, 3, 0 };
            var ints2 = new int[] { 5, 4, 2 };

            var result = from t in ints1
                         join x in ints2 on (t + 1) equals x
                         select t;

            Console.WriteLine("GoodCase2");

            foreach (int r in result)
            {
                Console.Write(r + " ");
            }
            Console.WriteLine();
        }

        public static void print()
        {
            Console.WriteLine("******************************************************************************************");
            Console.WriteLine("* You should use implicit typing in the declaration of query variable and range variable *");
            Console.WriteLine("******************************************************************************************");
        }

        static void Main(string[] args)
        {
            BadCase1();
            GoodCase1();

            BadCase2();
            GoodCase2();

            print();
        }
    }
}