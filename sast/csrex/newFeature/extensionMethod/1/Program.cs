using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ExtensionMethodBadCase
{
    class Program
    {
        static void Main(string[] args)
        {            
            UserObject user = null;
            bool b = user.IsNull();     /* BUG: FORWARD_NULL_CSHARP */
            if (b)
            {
                Console.WriteLine("The given input is null");
            }   
        }
    }
}