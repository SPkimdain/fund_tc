using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Quality
{
    class IsThisDeepCloneOrShallowClone : ICloneable        // @violation
    {
        private int content;
        private string s;

        public IsThisDeepCloneOrShallowClone(int content, string s) {
            this.content = content;
            this.s = s;
        }

        public string ToString() {

        }
    }

    class IsThisDeepCloneOrShallow                          // @safe
        {
            private int content;
            private string s;

            public IsThisDeepCloneOrShallow(int content, string s) {
                this.content = content;
                this.s = s;
            }

            public string ToString() {

            }
        }
}