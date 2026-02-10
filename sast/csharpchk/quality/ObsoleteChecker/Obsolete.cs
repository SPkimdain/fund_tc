using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;

namespace Quality
{
    class Obsolete
    {
        public Obsolete() {
            SCP = new SqlClientPermission(pstate, false); // @violation
        }
    }
}