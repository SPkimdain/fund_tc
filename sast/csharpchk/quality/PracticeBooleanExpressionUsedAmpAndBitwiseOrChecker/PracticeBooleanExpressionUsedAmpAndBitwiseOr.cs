using System;

namespace ConsoleApplication {
    class PracticeBooleanExpressionUsedAmpAndBitwiseOr
    {

        public static void BadCase1()
        {
            for (int i = 0; (i < 10) & (i % 2 != 0); i++) // @violation
            {
                Console.WriteLine(i);
            }
        }

        public static void BadCase2()
        {
            int i = 0;
            while(false & ++i == 1) // @violation
            {
                Console.WriteLine(i);
            }
        }

        public static void BadCase3()
        {
            Console.Write("Enter a dividend: ");
            var dividend = Convert.ToInt32(Console.ReadLine());

            Console.Write("Enter a divisor: ");
            var divisor = Convert.ToInt32(Console.ReadLine());

            if ((divisor != 0) & (dividend / divisor > 0))  // @violation
            {
                Console.WriteLine("Quotient: {0}", dividend / divisor);
            }
            else
            {
                Console.WriteLine("Attempted division by 0 ends up here.");
            }
        }

        public static void GoodCase1()
        {
            for (int i = 8; (i < 10) && (i % 7 != 0); i++)
            {
                Console.WriteLine(i);
            }
        }

       public static void GoodCase2()
       {
           int i = 0;
           while(false && ++i == 1)
           {
               Console.WriteLine(i);
           }
       }

       public static void GoodCase3()
       {
           Console.Write("Enter a dividend: ");
           var dividend = Convert.ToInt32(Console.ReadLine());

           Console.Write("Enter a divisor: ");
           var divisor = Convert.ToInt32(Console.ReadLine());

           if ((divisor != 0) && (dividend / divisor > 0))
           {
               Console.WriteLine("Quotient: {0}", dividend / divisor);
           }
           else
           {
               Console.WriteLine("Attempted division by 0 ends up here.");
           }
       }

        public int TestOperator(byte b)
        {
            if(b == 0x00) {
                return b & 0x04;
            }

            while(b != 0x00) {
                b = b & 0x04;
            }

            return b & 0x04;
        }
    }
}