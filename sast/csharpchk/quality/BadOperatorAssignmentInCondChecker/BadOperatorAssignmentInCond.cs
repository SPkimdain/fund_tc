using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Quality
{
    class BadOperatorAssignmentInCond
    {
        public void OperatorInCond(string a) {
            if(a = null)                                // @violation
            {

            }
            else if(a == null) {

            }

            switch(a = null) {                          // @violation
                default:
                    break;
            }

            for(int i=0; a = null; i++) {               // @violation

            }

            while(a = null) {                           // @violation

            }
        }
    }
}