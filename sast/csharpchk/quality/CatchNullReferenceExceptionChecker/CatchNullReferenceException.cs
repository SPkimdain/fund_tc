using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Quality
{
    class CatchNullReferenceException
    {
        public void DoSomething() {
            // do something
            try {
                InvokeMtd();
            }
            catch (NullReferenceException npe) {        // @violation
                // exception handling
            }
        }
    }
}