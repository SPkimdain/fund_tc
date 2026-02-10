using System;
namespace ConsoleApplication
{
    class PracticeObviousVariableTypeNotUsedImplicitTyping
    {
        public static void BadCase1()
        {
            string var1 = "This is clearly a string.";  // @violation
            int var2 = 27;  // @violation
            Int32 var3 = Convert.ToInt32(Console.ReadLine());   // @violation

            Console.WriteLine("BadCase1 :");
            Console.WriteLine(var1);
            Console.WriteLine(var2);
            Console.WriteLine(var3);
        }

        public static void BadCase2()
        {
            try
            {
                string var1 = 27.ToString();    // @violation
                int var2 = int.Parse("1");  // @violation
                decimal var3 = decimal.Parse("2");  // @violation
                Int32 var4 = Int32.Parse("3");  // @violation
                Byte var5 = Byte.Parse("4");    // @violation
                Int32 var6 = Convert.ToInt32("5");  // @violation

                Console.WriteLine("BadCase2 :");
                Console.WriteLine("VAR1 - " + var1);
                Console.WriteLine("VAR2 - " + var2);
                Console.WriteLine("VAR3 - " + var3);
                Console.WriteLine("VAR4 - " + var4);
                Console.WriteLine("VAR5 - " + var5);
                Console.WriteLine("VAR6 - " + var6);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.StackTrace);
            }
        }

        public static void GoodCase1()
        {
            var var1 = "This is clearly a string.";
            var var2 = 27;
            var var3 = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("GoodCase1");
            Console.WriteLine(var1);
            Console.WriteLine(var2);
            Console.WriteLine(var3);
        }

        public static void GoodCase2()
        {
            try
            {
                var var1 = 27.ToString();
                var var2 = int.Parse("1");
                var var3 = decimal.Parse("2");
                var var4 = Int32.Parse("3");
                var var5 = Byte.Parse("4");
                var var6 = Convert.ToInt32("5");

                Console.WriteLine("GoodCase2 :");
                Console.WriteLine("VAR1 - " + var1);
                Console.WriteLine("VAR2 - " + var2);
                Console.WriteLine("VAR3 - " + var3);
                Console.WriteLine("VAR4 - " + var4);
                Console.WriteLine("VAR5 - " + var5);
                Console.WriteLine("VAR6 - " + var6);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.StackTrace);
            }
        }

        public static void print()
        {
            Console.WriteLine("***********************************************************************************************");
            Console.WriteLine("* You should use implicit typing for local variables when the type of the variable is obvious *");
            Console.WriteLine("*        from right side of the assignment, or when the precise type is not important.        *");
            Console.WriteLine("***********************************************************************************************");
        }

        public static void Main(string[] args)
        {
            Console.Write("Input data : ");
            BadCase1();
            Console.WriteLine("------------------------------------------");
            Console.Write("Input data : ");
            GoodCase1();
            Console.WriteLine("------------------------------------------");
            BadCase2();
            Console.WriteLine("------------------------------------------");
            GoodCase2();
            Console.WriteLine("------------------------------------------");
            print();
        }

        public class SparrowTester
        {
            public object obj = new object();
            public string text = "text";
        }
    }
}