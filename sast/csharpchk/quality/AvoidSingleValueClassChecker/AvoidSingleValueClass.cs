using System;
using System.Text;

namespace SecurityLibrary
{
    public class BadClass {     // @violation
        int i;
    }

    public class GoodClass1 {
        int i;
        int j;
    }

    public class GoodClass1 {
        int i, j;
    }
}