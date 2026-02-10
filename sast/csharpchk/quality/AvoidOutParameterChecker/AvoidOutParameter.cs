using System;
using System.Text;

namespace SecurityLibrary
{
    public class BadClass
    {
        public bool BadMethod(out string reply)     // @violation
        {
            reply = String.Empty;
            reply = "test";
            
            return true;
        }

        private bool GoodMethod(out string reply)   // @safe
        {
            reply = String.Empty;
            reply = "test";

            return true;
        }
    }
}