/* WITH_CHECKERS : NULL_RETURN_STD_CSHARP */

using System;
using System.Collections.Generic;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
public class NullReturnStdTest
{
    public void test1() {
        Dictionary<string, string> d = new Dictionary<string, string>();
	    d.Add("txt", "notepad.exe");
	    d.Add("bmp", "mspaint.exe");
	    d.Add("dib", "mspaint.exe");
	    d.Add("rtf", "wordpad.exe");

	    Console.WriteLine("For key = \"db\", value = " + d["db"]);
	    if (d["db"].EndsWith(".exe")) {  /* BUG: NULL_RETURN_STD_CSHARP */
	        // exec
	    }
	}

	public void test2() {
	    Dictionary<string, string> d = new Dictionary<string, string>();
        d.Add("txt", "notepad.exe");
        d.Add("bmp", "mspaint.exe");
        d.Add("dib", "mspaint.exe");
        d.Add("rtf", "wordpad.exe");

        Console.WriteLine("For key = \"txt\", value = {0}.", d["txt"]); /* safe */
        if (d["txt"].EndsWith(".exe")) {
            // exec
        }
    }
}