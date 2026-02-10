using System;
using System.Text;

namespace badNameSpace      // @violation
{
    public class BadClass
    {

    }
}

namespace GoodNameSpace     // @safe
{
    public class GoodClass
    {

    }
}