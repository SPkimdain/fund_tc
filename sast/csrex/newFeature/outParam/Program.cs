using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Web;

namespace newFeatures
{
    class Program
    {
        private static int x;

        private const int y = 10;

        private static string z = "";

        private const string w = GetABC();

        private int fieldX = 0;
        private string fieldY;

        static Program() {
            x = 5;
            initParam(z);
        }

        public Program(int t) {
            fieldX = t;
            fieldY = t.ToString();
        }

        private static string GetABC() {
            return "abc";
        }

        static void Main(string[] args)
        {
            string s = args[1];

            int z = Int32.Parse(s) + 3; /* BUG: INTEGER_OVERFLOW_CSHARP */

            // in callee
            initParamRef(ref s); /* BUG: INTEGER_OVERFLOW_CSHARP */
            // now s has constant string

            initParam(out string k);

            new HttpCookie().Expires = k; /* BUG: PERSISTENT_COOKIE_ASPNET */

            int w = Int32.Parse(s) + 5; // not bug

            new HttpCookie().Expires = s; /* BUG: PERSISTENT_COOKIE_ASPNET */
        }

        static private void initParamRef(ref String s)
        {
            int z = Int32.Parse(s) + 3;
            s = ott;
        }

        static private void initParam(out String s)
        {
            s = ott;
        }
        private const string ott = "123";
    }
}
