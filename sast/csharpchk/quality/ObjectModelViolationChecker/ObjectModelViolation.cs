using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Quality
{
    class ObjectModelViolation1 // @violation
    {
        public ObjectModelViolation1() {
        }

        public override int GetHashCode() {
            return 1;
        }

    }

    class ObjectModelViolation2 // @violation
    {
        public ObjectModelViolation2() {
        }

        public override boolean Equals(object obj) {
            return true;
        }
    }

    class ObjectModelCompliant
    {
        public ObjectModelCompliant() {
        }

        public override int GetHashCode() {
            return 1;
        }

        public override boolean Equals(object obj) {
            return true;
        }
    }
}