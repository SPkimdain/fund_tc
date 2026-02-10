using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Web;

namespace NewNonghyupCheckers
{
    class ImproperAuthorizationTest
    {
        private String id;

        public void AuthzCriticalMethod_1() // @violation
        {

        }

        [Authorize]
        public void AuthzCriticalMethod_2()
        {

        }

        [MyAuthorize]
        public void AuthzCriticalMethod_3()
        {

        }
    }
}