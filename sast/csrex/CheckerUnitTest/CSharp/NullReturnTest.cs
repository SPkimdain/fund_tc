/* WITH_CHECKERS : NULL_RETURN_CSHARP */

using System;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
public class NullReturnTest
{
    public string x;

    public int Compare(NullReturnTest o1, NullReturnTest o2)
    {
        int result = 0;

        string s1 = GetX(o1);
        string s2 = GetX(o2);

        string ss1 = s1.ToLower(CultureInfo.CurrentCulture); /* BUG: NULL_RETURN_CSHARP */
        string ss2 = s2.ToLower(CultureInfo.CurrentCulture); /* BUG: NULL_RETURN_CSHARP */ // This bug will be filtered when option show_followers is off

        result = s1.CompareTo(s2); /* BUG: NULL_RETURN_CSHARP */ // This bug will be filtered when option show_followers is off

        return result;
	}

	public string GetX(NullReturnTest o) {
	    string ret = null;
	    if (o != null) {
	        ret = o.x;
	        return ret;
	    }
	    return ret;
	}
}