using System;

namespace GlobalizationLibrary
{
    class WriteSpecialFolders
    {
        static void Main()
        {
            string string0 = "C:";

            // Each of the following three strings violates the rule.
            string string1 = @"\Documents and Settings"; // @violation
            string string2 = @"\All Users";    // @violation
            string string3 = @"\Application Data"; // @violation
            Console.WriteLine(string0 + string1 + string2 + string3);

            // The following statement satisfies the rule.
            Console.WriteLine(Environment.GetFolderPath(
            Environment.SpecialFolder.CommonApplicationData));
        }
    }
}