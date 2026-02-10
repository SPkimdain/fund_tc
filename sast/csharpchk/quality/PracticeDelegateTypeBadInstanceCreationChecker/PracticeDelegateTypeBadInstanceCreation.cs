using System;
namespace ConsoleApplication
{
    public delegate void Del3(string message);

    class PracticeDelegateTypeBadInstanceCreation
    {

        public delegate void Del(string message);

        public static void DelegateMethod(string message)
        {
            Console.WriteLine(message);
        }

        public Del badDelField = new Del(DelegateMethod); // @violation
        public Del goodDelField = DelegateMethod;

        public static Del badDelFieldNotInitialization;
        public static Del goodDelFieldNotInitialization;

        public static void BadCase1()
        {
            badDelFieldNotInitialization = new Del(DelegateMethod); // @violation
            Del localDel = new Del(DelegateMethod); // @violation

            badDelFieldNotInitialization("BadCase1_1 : Field no initialization");
            localDel("BadCase1_2 : Local Variable");
        }

        public static void GoodCase1()
        {
            goodDelFieldNotInitialization = DelegateMethod;
            Del localDel = DelegateMethod;

            goodDelFieldNotInitialization("GoodCase1_1 : Field no initialization");
            localDel("GoodCase1_2 : Local Variable");
        }

        public static void print()
        {
            Console.WriteLine("****************************************************************************");
            Console.WriteLine("* You should use the concise syntax to create instances of a delegate type *");
            Console.WriteLine("****************************************************************************");
        }

    }

    public class TempClass
    {
        public delegate void Del2(string message);
    }

    class InheritanceClass : PracticeDelegateTypeBadInstanceCreation
    {
        public static void BadCase2()
        {
            Del badLocal = new Del(DelegateMethod); // @violation
            TempClass.Del2 staticDel = new TempClass.Del2(DelegateMethod);  // @violation
            Del3 globalDel = new Del3(DelegateMethod);  // @violation

            badLocal("BadCase3 : Inheritance");
            staticDel("BadCase3 : Static Of Another class");
            globalDel("BadCase3 : Global in namespace");
        }

        public static void GoodCase2()
        {
            Del badLocal = DelegateMethod;
            TempClass.Del2 staticDel = DelegateMethod;
            Del3 globalDel = DelegateMethod;

            badLocal("GoodCase3 : Inheritance");
            staticDel("GoodCase3 : Static of Another class");
            globalDel("GoodCase3 : Global in namespace");
        }

        public static void Main(string[] args)
        {
            BadCase1();
            Console.WriteLine("------------------------------------------------------------");
            GoodCase1();
            Console.WriteLine("------------------------------------------------------------");
            BadCase2();
            Console.WriteLine("------------------------------------------------------------");
            GoodCase2();
            Console.WriteLine("------------------------------------------------------------");
            print();
        }
    }
}