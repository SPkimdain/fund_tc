using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ExtensionMethodGoodCase
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
            if (obj == null)
            {                
                return true;
            }
            return false;
            
        }
        
    }
}
