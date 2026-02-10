using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication14
{
    class Program
    {
        private String[] userRoles;

        public void SetUserRoles1(String[] userRoles)
        {
            this.userRoles = userRoles; // @violation
        }

        public void SetUserRoles2(String[] userRoleArray)
        {
            userRoles = userRoleArray; // @violation
        }
    }
}
