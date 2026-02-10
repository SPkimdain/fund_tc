using System;
using System.Text;

namespace SecurityLibrary
{
    public class BadClass
    {
        public bool BadMethod(string reply)
        {
            string BadLocalVar;     // @violation
            
            return true;
        }

        public bool GoodMethod(string reply)
        {
            string goodLocalVar;    // @safe

            return true;
        }
    }
}