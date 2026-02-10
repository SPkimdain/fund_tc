using System;
using System.Text;

namespace SecurityLibrary
{
    public class MutableReferenceTypes
    {
        static protected readonly StringBuilder SomeStringBuilder; // @violation

        static MutableReferenceTypes()
        {
            SomeStringBuilder = new StringBuilder();
        }
    }
}