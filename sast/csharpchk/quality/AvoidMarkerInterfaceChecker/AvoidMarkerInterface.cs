using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Quality
{
    public interface IBadInterface      // @violation
    {

    }

    public interface IGoodInterface     // @safe
    {
        void print();
    }
}
