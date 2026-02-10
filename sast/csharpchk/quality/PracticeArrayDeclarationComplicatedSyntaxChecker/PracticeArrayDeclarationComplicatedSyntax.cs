using System;

namespace ConsoleApplication1
{
    class PracticeArrayDeclarationComplicatedSyntax
    {
        public static void BadCase1()
            {
                var vowels1 = new string[5]; // @violation
                vowels1[0] = "a";
                vowels1[1] = "e";
                vowels1[2] = "i";
                vowels1[3] = "o";
                vowels1[4] = "u";

                foreach (string element in vowels1)
                {
                    Console.WriteLine(element);
                }
            }

        var vowels1_1 = new string[5]; // @violation

       public static void BadCase2()
       {
           vowels1_1[0] = "a";
           vowels1_1[1] = "e";
           vowels1_1[2] = "i";
           vowels1_1[3] = "o";
           vowels1_1[4] = "u";

           foreach (string element in vowels1_1)
           {
               Console.WriteLine(element);
           }
       }

        public static void GoodCase1()
        {
            string[] vowels2 = { "a", "e", "i", "o", "u" };

            foreach (string element in vowels2)
            {
                Console.WriteLine(element);
            }
        }

        public static void GoodCase2()
        {
            var vowels3 = new string[] { "a", "e", "i", "o", "u" };

            foreach (string element in vowels3)
            {
                Console.WriteLine(element);
            }
        }

        public static void GoodCase3()
        {
            string[] vowels4 = { "a", "e", "i", "o", "u" };

            foreach (string element in vowels4)
            {
                Console.WriteLine(element);
            }
        }

        public static void GoodCase4()
        {
            string[] array1 = new string[10], array2 = new string[20];

            for(int i = 0; i < 2; i++)
            {
                for(int k = 0; k < 5; k++)
                {
                    array1[((i + 1) * (k + 1)) -1] = "abc";
                }
                array2[i*1] = "cba";
            }
        }

        public static void Main(string[] args)
        {
            BadCase1();
            GoodCase1();
            GoodCase2();
            GoodCase3();
        }

     public Class2 C2 { get; set; } = null;

        public Class1()
        {
            if (C2 == null)
                C2 = new Class2();

            C2.Test1_1 += OnTest1_1;
            C2.Test1_2 += OnTest1_2;
            C2.Test1_3 += OnTest1_3;
            C2.Test1_4 += OnTest1_4;
            C2.Test1_5 += OnTest1_5;
            C2.Test2_1 += OnTest2_1;
            C2.Test2_2 += OnTest2_2;
            C2.Test2_3 += OnTest2_3;
            C2.Test2_4 += OnTest2_4;
            C2.Test2_5 += OnTest2_5;

            var arr1 = new string[5];
            var i = 5;
            var arr2 = new string[i];
            arr1.CopyItems(arr2, i);
            arr2 = arr2.Concat(new string[2] { "", "" }).ToArray();
            var arr3 = new string[i];
            arr3 = arr3.Union(new string[2] { "", "" }).ToArray();
        }
    }
}