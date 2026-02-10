using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Quality
{
    class EmptyCatchBlock
    {
        public EmptyCatchBlock() {
        }

        public void DoSome() {
            try {
              InvokeMtd();
            } catch (Exception e) {     // @violation

            }
        }
    }
}