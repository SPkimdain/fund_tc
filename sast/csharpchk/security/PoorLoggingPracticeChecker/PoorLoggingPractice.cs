using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Quality
{
    class PoorLoggingPractice
    {
        public PoorLoggingPractice() {
        }

        public void Log() {
            Console.WriteLine("sensitive info"); // @violation
        }
    }
}