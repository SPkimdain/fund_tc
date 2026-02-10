using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ExtensionMethodBadCase
{
    public static class NullUtil
    {
        public static bool IsNullString(this string obj)
        {
            if (obj == null)
            {
                return true;
            }
            return false;
        }

        public static bool IsNull(this UserObject obj)
        {
            string name = obj.ToString();                        
            if (name == "null")
            {                
                return true;
            }
            return false;            
        }
    }
}
