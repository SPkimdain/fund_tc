using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        public static void BadMethod()
        {
            string str = new String(new char[] {'a', 'b'});     // @violation
            char[] letters = {'A', 'B', 'C'};
            char* letters2 = {'A', 'B', 'C'};
            sbyte* letters3 = {'A', 'B', 'C'};
            string[] stringArray = new String[6];
            string[] weekDays = new string[] { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
            string alphabet = new string(letters);
            string number = new string('1');                    // @violation
            string empty = new String();                        // @violation
        }

        public static void GoodMethod()
        {
            string str = "ab";
            char[] letters = {'A', 'B', 'C'};
            char* letters2 = {'A', 'B', 'C'};
            sbyte* letters3 = {'A', 'B', 'C'};
            string[] stringArray = new string[6];
            string[] weekDays = new string[] {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
            string alphabet = new string(letters);
            string number = "1";
            string empty = String.Empty;
        }

        static void Main(string[] args)
        {
            BadMethod();
        }
    }
}
