using System;
using System.Text;

namespace SecurityLibrary
{
    public struct BadStruct
    {
        static protected readonly StringBuilder SomeStringBuilder;      // @violation
        static protected readonly string SomeString;                    // @safe
    }
}