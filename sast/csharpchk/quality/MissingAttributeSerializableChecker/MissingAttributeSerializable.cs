using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;

namespace Quality
{
    class MissingAttributeSerializable : ISerializable  // @violation
    {
        public MissingAttributeSerializable()
        {
        }
    }
}