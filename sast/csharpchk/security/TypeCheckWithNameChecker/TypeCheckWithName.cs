using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TypeCheckWithName
{
    class Program
    {
        private someThing.Special unknownType;

        public void doSomething()
        {
            if (unknownType.GetType().FullName == "someThing.Special") // @violation
            {
                Console.WriteLine("do something important");
            }
        }
    }
}
