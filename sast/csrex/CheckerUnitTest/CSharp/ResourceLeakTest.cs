/* WITH_CHECKERS : RESOURCE_LEAK_CSHARP */

using System.IO;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
public class StreamTest {
    string pathSource = "c:\\tests\\source.txt";
    string pathNew = "c:\\tests\\newFile.txt";

    public void test() { /* BUG: RESOURCE_LEAK_CSHARP */ // fsSource is not closed
        FileStream fsSource = new FileStream(pathSource, FileMode.Open, FileAccess.Read); // leaked resource

        byte[] bytes = new byte[fsSource.Length];
        long numBytesToRead = fsSource.Length;
        long numBytesRead = 0;

        while(numBytesToRead > 0) {
            long n = fsSource.Read(bytes, numBytesRead, numBytesToRead);

            if (n==0) break;
            numBytesRead += n;
            numBytesToRead -= n;
        }

        using(FileStream fsNew = new FileStream(pathNew, FileMode.Create, FileAccess.Write)) { // NOT BUG
            fsNew.Write(bytes, 0, numBytesRead);
        }
    }
}