using System;
using System.Text;

namespace SecurityLibrary
{
    public class BadClass
    {
        public bool BadMethod(string Reply)     // @violation
        {
            return true;
        }

        public bool GoodMethod(string reply)    // @safe
        {
            return true;
        }
    }
}