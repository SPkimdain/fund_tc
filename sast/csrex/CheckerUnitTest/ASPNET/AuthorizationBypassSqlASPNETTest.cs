/* WITH_CHECKERS : AUTHORIZATION_BYPASS_SQL_ASPNET */

/*****************************************************/
/* Converted by ASPNETConv: ASP.NET Converter module */
/* Generated at: 2014-18-06 20:19:25                 */
/*****************************************************/
// Originated from C:\Users\fasoo-ybj\Desktop\aspnet\benchmark\blogengine\src\Account\login.aspx

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
namespace ASP {
    using System;
    using System.Collections.Generic;
    using System.IO;
    using System.Linq;
    using System.Net;
    using System.Web;
    using System.Web.Helpers;
    using System.Web.Security;
    using System.Web.UI;
    using System.Web.WebPages;
    using System.Web.Mvc;
    using System.Web.Mvc.Ajax;
    using System.Web.Mvc.Html;
    using System.Web.Routing;
    using System.Data.Odbc;
    using System.Data.SqlClient;

    public class SqlInjectionTest : Account.Login {

        HttpRequest Request;
        HttpResponse Response;

        public SqlInjectionTest() {
        }

        void ButtonClickBad(object sender, string connect, EventArgs e)
        {
            string id = Request.QueryString["ID"];
            string query = "Select * From Products Where ProductID = @ProductID";

            using (var conn = new SqlConnection(connect))
            {
                using (var cmd = new SqlCommand(query, conn))
                {
                    cmd.Parameters.AddWithValue("@ProductID", Convert.ToInt32(id)); /* BUG: AUTHORIZATION_BYPASS_SQL_ASPNET */
                    conn.Open();
                    cmd.ExecuteReader();
                }
            }
        }

        void ButtonClickGood(object sender, string connect, EventArgs e)
        {
            string id = Request.QueryString["ID"];
            string query = "Select * From Products Where ProductID = @ProductID";

            using (var conn = new SqlConnection(connect))
            {
                using (var cmd = new SqlCommand(query, conn))
                {
                    int idInt = Convert.ToInt32(id);
                    if (idInt > 0 && idInt < 10000) {
                        cmd.Parameters.AddWithValue("@ProductID", idInt); // Not bug
                        conn.Open();
                        cmd.ExecuteReader();
                    }
                }
            }
        }
    }
}
