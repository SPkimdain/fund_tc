/* WITH_CHECKERS : FORWARD_NULL_CSHARP */

using System;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
public class ForwardNullTest
{
    public void test()
    {
        Intra(6);
        Intra(5);
        Intra(4); // Bug in callee
    }

    int Intra(int level)
    {
	    Object x = null;
	    if (level > 5)
		    x = new Object();
	    if (level < 5)
		    return x.GetHashCode(); /* BUG: FORWARD_NULL_CSHARP */ // if level < 5
	    return 0;
	}
}