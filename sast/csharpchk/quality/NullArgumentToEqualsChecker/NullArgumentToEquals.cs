using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Quality
{
    class NullArgumentToEquals
    {
        public NullArgumentToEquals() {
        }

        public void DoNullCheck(String s) {
            if(s.Equals(null)) { // @violation
            }
        }

        public void DoNullCheckSound(String s) {
            if(s != null) {
            }
        }
    }
}