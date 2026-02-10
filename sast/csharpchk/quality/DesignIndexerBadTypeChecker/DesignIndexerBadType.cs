using System;

namespace DesignLibrary
{
    public class Months
    {
        string[] month = new string[] {"Jan", "Feb", "..."};

        public string this[bool index] // @violation
        {
            get
            {
                return month[index];
            }
        }
    }
}