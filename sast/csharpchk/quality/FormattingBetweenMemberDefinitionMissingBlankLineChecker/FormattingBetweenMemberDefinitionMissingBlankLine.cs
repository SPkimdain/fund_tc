using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpCheckerTest
{
    class FormattingBetweenMemberDefinitionMissingBlankLine
    {
        private int badCaseNum;
        public int BadCaseNum
        {
            get
            {
                return badCaseNum;
            }
            set
            {
                this.badCaseNum = value;
            }
        }
        public static void BadCase2()   // @violation
        {
            Console.WriteLine("BadCase2 method in class after property declaration");
        }

        public static void BadCase1_1()
        {
            Console.WriteLine("Before BadCase1_1 method in class");
        }
        public static void BadCase1_2() // @violation
        {
            Console.WriteLine("Current BadCase1_2 method in class");
        }

        public static void GoodCase1_1()
        {
            Console.WriteLine("Before GoodCase1_1 method in calss");
        }

        public static void GoodCase1_2()
        {
            Console.WriteLine("Current GoodCase1_2 method in class");
        }

        public static void print()
        {
            Console.WriteLine("*************************************************************************************");
            Console.WriteLine("* Add at least one blank line between method declarations and property declarations *");
            Console.WriteLine("*************************************************************************************");
        }

        static void Main(string[] args)
        {
            BadCase1_1();
            BadCase1_2();
            BadCase2();
            GoodCase1_1();
            GoodCase1_2();

            print();
        }
    }

    interface INoIntervalMethodDefAndPropertyDef
    {
        int BadCaseNum
        {
            get;
            set;
        }
        void BadCase2();  // @violation

        void BadCase1_1();
        void BadCase1_2();    // @violation

        void GoodCase1_1();

        void GoodCase1_2();
    }
}
