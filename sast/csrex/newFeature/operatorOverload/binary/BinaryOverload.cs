using System;

namespace OpOver {
    public class BinaryOverload {
        private string taintCarrier;

        public BinaryOverload(string x) {
            taintCarrier = x;
        }

        public static string operator +(BinaryOverload a, string b) {
            return a.taintCarrier + b;
        }

        public static string operator -(BinaryOverload a, string b) {
            return a.taintCarrier + b;
        }

        public static void Main(string[] args) {
            BinaryOverload a = new BinaryOverload(args[0]);
            string b = a + "12";
            int x = Int32.Parse(b) + 1; /* BUG: INTEGER_OVERFLOW_CSHARP */

            BinaryOverload c = new BinaryOverload(args[1]);
            string d = c - "12";
            int y = Int32.Parse(d) + 3; /* BUG: INTEGER_OVERFLOW_CSHARP */
        }
    }
}