using System;
using System.Text;

namespace ConsoleApplication
{
    class PracticeStringBuilderShortStringConcatenation
    {
        var fieldStringBuilder = new StringBuilder();

        public static StringBuilder BadCase1()
        {
            var stringBuilder = new StringBuilder();
            stringBuilder.Append("UseStringBuilder");   // @violation
            stringBuilder.Append("AppendToConcatenate");    // @violation
            stringBuilder.Append("ShortStrings");   // @violation

            return stringBuilder;
        }

        public static StringBuilder BadCase2()
        {
            StringBuilder sb = new StringBuilder();
            var stringBuilder = new StringBuilder();
            if(sb != null && stringBuilder != null && fieldStringBuilder != null)
            {
                sb.Append("A StringBuilder object is generated."); // @violation
                stringBuilder.Append("Another StringBuilder object is generated"); // @violation
                fieldStringBuilder.Append("A StringBuilder object in field is generated");
            }
            return sb;
        }

        public static string GoodCase1()
        {
            string className = "UseStringBuilder" + "AppendToConcatenate" + "ShortStrings";

            return className;
        }

        public static StringBuilder GoodCase2()
        {
            var stringBuilder = new StringBuilder();

            for (int i = 0; i < 10000; i++)
            {
                stringBuilder.Append(i.ToString() + " ");
            }

            do
            {
                stringBuilder.Append("inDo ");
            } while (stringBuilder.Length < 10100);

            while(stringBuilder.Length < 10200)
            {
                stringBuilder.Append("inWhile ");
            }

            return stringBuilder;
        }

        public static void Main(string[] args)
        {
            Console.WriteLine(BadCase1());
            Console.WriteLine(GoodCase1());
            Console.WriteLine(GoodCase2());
        }
    }
}