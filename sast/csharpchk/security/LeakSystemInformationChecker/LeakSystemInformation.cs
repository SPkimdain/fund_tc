using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Quality
{
    class LeakSystemInformation
    {
        public LeakSystemInformation() {
        }

        public void DoSome() {
            try {
                // do something
            } catch (Exception e) {
                Console.WriteLine(e); // @violation
            }
        }
    }
}