/* WITH_CHECKERS : DIVIDE_BY_ZERO_CSHARP */

using System;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
public class Dz
{
    public Dz()
    {
    }

    public int Execute(bool b)
    {
        int x = 10;
        int y = 20;
        int z = 30;

        if (b) return z / (y - x - x); /* BUG: DIVIDE_BY_ZERO_CSHARP */
        else return y/x; // NOT BUG
    }
}