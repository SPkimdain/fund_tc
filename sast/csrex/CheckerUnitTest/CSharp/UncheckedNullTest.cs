/* WITH_CHECKERS : UNCHECKED_NULL_CSHARP */

using System;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
public class UncheckedNullTest
{
    string p;

    public string testBugCase(object x)
    {
        if (x != null) {
            p = x.ToString();
        }

        if (x == null) {
            p = "null";
        }

        return x.ToString(); /* BUG: UNCHECKED_NULL_CSHARP */
    }

    public string testNotBugCase(object x) {
        if (x == null) {
            return "null";
        }

        return x.ToString(); // Not bug
    }
}