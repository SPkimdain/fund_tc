/* WITH_CHECKERS : SQL_INJECTION_ASPNET */

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
    using System.Data;
    using System.Data.Odbc;

    public class SqlInjectionTest : Account.Login {
        HttpRequest Request;
        HttpResponse Response;

        public SqlInjectionTest() {
        }

        void ButtonClickBad(object sender, string connect, EventArgs e)
        {
            string usrinput = Request.QueryString["ID"];
            string query = "Select * From Products Where ProductID = " + usrinput;

            using (var conn = new OdbcConnection(connect))
            {
                using (var cmd = new OdbcCommand(query, conn))
                {
                    conn.Open();
                    cmd.ExecuteReader(); /* BUG: SQL_INJECTION_ASPNET */
                }
            }
        }

        void ButtonClickGood(object sender, string connect, EventArgs e)
        {
            string id = Request.QueryString["ID"];
            string query = "Select * From Products Where ProductID = @ProductID";

            using (var conn = new OdbcConnection(connect))
            {
                using (var cmd = new OdbcCommand(query, conn))
                {
                    cmd.Parameters.AddWithValue("@ProductID", Convert.ToInt32(id));

                    conn.Open();
                    cmd.ExecuteReader(); // NOT BUG
                }
            }
        }
    }
}
