/* WITH_CHECKERS : INTEGER_OVERFLOW_CSHARP */

using System;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
public class IntegerOverflow
{
    public static void Main(string[] args) {
        int usrNum = Int32.Parse(args[0]);
        string[] array = {"one", "two", "three"};
        string numStr = array[usrNum]; /* BUG: INTEGER_OVERFLOW_CSHARP */
    }
}