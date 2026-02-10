using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ExtensionMethod
{
    class UserObject
    {
        string property;
        public UserObject()
        {
            property = "user created object"; // password here! // @violation
        }
    }
}