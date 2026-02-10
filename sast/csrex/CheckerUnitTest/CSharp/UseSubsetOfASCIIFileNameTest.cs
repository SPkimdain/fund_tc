/* WITH_CHECKERS : USE_A_SUBSET_OF_ASCII_FOR_FILE_AND_PATH_NAMES_CSHARP */

using System;
using System.IO;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
public class UseSubsetASCII
{
    public static void Main(string[] args) {
        string name = "C:\\Temp\\" + args[0];
        using (FileStream fs = File.Open(name, FileMode.Open, FileAccess.Write, FileShare.None)) /* BUG: USE_A_SUBSET_OF_ASCII_FOR_FILE_AND_PATH_NAMES_CSHARP */
        {
            Byte[] info = new UTF8Encoding(true).GetBytes("Test Text");
            fs.Write(info, 0, info.Length);
        }

        string name2 = "C:\\Temp\\" + "\\uD8AB";
        using (FileStream fs = File.Open(name2, FileMode.Open, FileAccess.Write, FileShare.None)) /* BUG: USE_A_SUBSET_OF_ASCII_FOR_FILE_AND_PATH_NAMES_CSHARP */
        {
            Byte[] info = new UTF8Encoding(true).GetBytes("Test Text");
            fs.Write(info, 0, info.Length);
        }
    }
}