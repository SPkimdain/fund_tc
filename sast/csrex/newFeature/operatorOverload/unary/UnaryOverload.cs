using System;

namespace OpOver {
    public class UnaryOverload {
        public string taintCarrier;

        public UnaryOverload(string x) {
            taintCarrier = x;
        }

        public static string operator -(UnaryOverload a) {
            return a.taintCarrier;
        }

        public static UnaryOverload operator ++(UnaryOverload a) {
            return new UnaryOverload(a.taintCarrier + "1");
        }

        public static void Main(string[] args) {
            UnaryOverload a = new UnaryOverload(args[0]);
            string b = -a;
            int x = Int32.Parse(b) + 1; /* BUG: INTEGER_OVERFLOW_CSHARP */

            UnaryOverload c = new UnaryOverload(args[1]);
            string d = c + "12";
            int y = Int32.Parse(d) + 3;

            UnaryOverload e = new UnaryOverload(args[2]);
            string f = e++.taintCarrier;
            int z = Int32.Parse(f) + 1; /* BUG: INTEGER_OVERFLOW_CSHARP */

            UnaryOverload g = new UnaryOverload(args[3]);
            string h = (++g).taintCarrier;
            int w = Int32.Parse(h) + 1; /* BUG: INTEGER_OVERFLOW_CSHARP */
        }
    }
}