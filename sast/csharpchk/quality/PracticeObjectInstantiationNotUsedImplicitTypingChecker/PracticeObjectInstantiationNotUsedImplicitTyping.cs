using System;

namespace ConsoleApplication
{
    class PracticeObjectInstantiationNotUsedImplicitTyping
    {
        public static void BadCase1()
        {
            TestClass testClass1 = new TestClass(); // @violation
            testClass1.print("testClass1");
        }

        public static void GoodCase1()
        {
            var testClass2 = new TestClass();
            testClass2.print("testClass2");
        }

        public static void Main(string[] args)
        {
            BadCase1();
            GoodCase1();
        }
    }

    class TestClass
    {
        public void print(string postfix)
        {
            Console.WriteLine("Print text in TestClass " + postfix);
        }
    }

    public class SparrowTester
    {
        public object obj = new object();
        public string text = "text";
    }
}