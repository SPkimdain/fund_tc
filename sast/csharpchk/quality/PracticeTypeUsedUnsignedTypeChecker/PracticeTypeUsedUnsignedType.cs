using System;
using System.Collections.Generic;

namespace ConsoleApplication
{
    class PracticeTypeUsedUnsignedType
    {
        public static void BadCase1()
        {
            uint unsignedInt = 10;  // @violation
            ulong unsignedLong = 10;    // @violation
            ushort unsignedShort = 10;  // @violation

            Console.WriteLine("unsignedInt : " + unsignedInt);
            Console.WriteLine("unsignedLong : " + unsignedLong);
            Console.WriteLine("unsignedShort : " + unsignedShort);
        }

        public static void BadCase2()
        {
            var unsigned = new uint[3] { 1, 2, 3 }; // @violation

            foreach(int element in unsigned)
            {
                Console.WriteLine(element);
            }
        }

        public static void BadCase3()
        {
            List<uint> unsignedList = new List<uint>(); // @violation
            unsignedList.Add(1);
            unsignedList.Add(2);

            foreach(uint unsigned in unsignedList)  // @violation
            {
                Console.WriteLine(unsigned);
            }
        }

        public static void GoodCase1()
        {
            int signedInt = 10;
            long signedLong = 10;
            short signedShort = 10;

            Console.WriteLine("singedInt : " + signedInt);
            Console.WriteLine("signedLong : " + signedLong);
            Console.WriteLine("signedShort : " + signedShort);
        }

        public static void GoodCase2()
        {
            var signed = new int[3] { 1, 2, 3 };

            foreach(int integer in signed)
            {
                Console.WriteLine(integer);
            }
        }

        public static void GoodCase3()
        {
            List<int> signedList = new List<int>();
            signedList.Add(1);
            signedList.Add(2);

            foreach(int integer in signedList)
            {
                Console.WriteLine(integer);
            }
        }

        public static void Main(String[] args)
        {
            BadCase1();
            BadCase2();
            BadCase3();

            GoodCase1();
            GoodCase2();
            GoodCase3();
        }
    }
}