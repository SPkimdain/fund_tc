/* WITH_CHECKERS : TOCTOU_RACE_CONDITION_CSHARP */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
namespace Security
{
    class TOCTOU
    {
        public void DeleteFile()
        {
            if (File.Exists("filepath1"))
            {
                File.Delete("filepath1"); /* BUG: TOCTOU_RACE_CONDITION_CSHARP */
            }
        }

        public void ReadFfile()
        {
            if(File.Exists("filepath2"))
            {
                File.ReadAllLines("filepath2"); /* BUG: TOCTOU_RACE_CONDITION_CSHARP */
            }
        }

		public void ReadFfile2()
        {
			String f = "file";
            if(File.Exists(f))
            {
                File.ReadAllLines(f); /* BUG: TOCTOU_RACE_CONDITION_CSHARP */
            }
        }

		public void ReadFile3(String f)
		{
			if(File.Exists(f))
            {
                File.ReadAllLines(f); /* BUG: TOCTOU_RACE_CONDITION_CSHARP */
            }
		}

		public void CallReadF()
		{
			ReadFile3("can you find this file huh?");
		}
    }
}
