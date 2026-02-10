using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ExtensionMethodGoodCase
{
    class Program
    {
        static void Main(string[] args)
        {
            UserObject user = null;
            bool b = user.IsNull();
            if (b)
            {
                Console.WriteLine("The given input is null");
            }   
        }
    }
}