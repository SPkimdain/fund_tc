using System;

namespace ConsoleApplication
{
    class DerivedClass : BaseClass
    {
        public static string overrideMemberString = "In the Derived Class";

        public static void OverrideMemberMethod()
        {
            Console.WriteLine("Call a override member method in the DerivedClass");
        }
    }

    class BaseClass
    {
        public static string memberStringOfBaseClass = "The Member String of the BaseClass";
        public static string overrideMemberString = "In the BaseClass";

        public static void BaseMemberMethod()
        {
            Console.WriteLine("Call a member method in the BaseClass");
        }

        public static void OverrideMemberMethod()
        {
            Console.WriteLine("Call a override member method in the BaseClass");
        }


        public static void Print()
        {
            Console.WriteLine("******************************************************************");
            Console.WriteLine("* You should not qualify a static member defined in a base class *");
            Console.WriteLine("*                with the name of a derived class                *");
            Console.WriteLine("******************************************************************");
        }
    }

    class PracticeCallToStaticMemberWithDerivedClassName
    {
        public static void BadCase1()
        {
            Console.WriteLine("BaseCase1 :");
            DerivedClass.BaseMemberMethod();    // @violation
        }

        public static void BadCase2()
        {
            Console.WriteLine("BadCase2 :");
            Console.WriteLine(DerivedClass.memberStringOfBaseClass); // @violation
        }

        public static void GoodCase1()
        {
            Console.WriteLine("GoodCase1 :");
            BaseClass.BaseMemberMethod();
        }

        public static void GoodCase2()
        {
            Console.WriteLine("GoodCase2 :");
            Console.WriteLine(BaseClass.memberStringOfBaseClass);
        }

        public static void GoodCase3()
        {
            Console.WriteLine("GoodCase3 :");
            BaseClass.OverrideMemberMethod();
            DerivedClass.OverrideMemberMethod();
            Console.WriteLine(BaseClass.overrideMemberString);
            Console.WriteLine(DerivedClass.overrideMemberString);
        }

        public static void Main(string[] args)
        {
            BadCase1();
            Console.WriteLine();
            BadCase2();
            Console.WriteLine();
            GoodCase1();
            Console.WriteLine();
            GoodCase2();
            Console.WriteLine();
            GoodCase3();
            Console.WriteLine();
            BaseClass.Print();
        }
    }

    public class ExClass {
      public static void ExFunc() {
        Console.WriteLint("Test");
      }
    }

    public class TestClass {
      public ExClass ExClass {
        get;
        set;
      }

      public void TestFunc() {
        ExClass.ExFunc();
      }
    }
}