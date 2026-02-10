using System;

namespace OpOver {
    public class CastOverload {
        public string taintCarrier;

        public CastOverload(string x) {
            taintCarrier = x;
        }

        public static explicit operator int(CastOverload a) {
            return Int32.Parse(a.taintCarrier);
        }

        public static void Main(string[] args) {
            CastOverload a = new CastOverload(args[0]);
            int x = (int)a + 6; /* BUG: INTEGER_OVERFLOW_CSHARP */

            long y = (long)a + 3;
        }
    }
}