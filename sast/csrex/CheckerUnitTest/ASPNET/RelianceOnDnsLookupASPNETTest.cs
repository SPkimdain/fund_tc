/* WITH_CHECKERS : RELIANCE_ON_DNS_LOOKUPS_IN_A_SECURITY_DECISION_ASPNET */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
namespace Outter.Inner
{
    namespace Deeper
    {
        public partial class RelianceOnDns : System.Web.UI.Page
        {
            bool trusted;

            protected void Page_Load(object sender, EventArgs e)
            {
                if (Request.ServerVariables["REMOTE_HOST"] != null)
                {
                    string remoteIpStr = Request.ServerVariables["REMOTE_HOST"];
                    IPAddress remoteIp = IPAddress.Parse(remoteIpStr);
                    IPHostEntry hostInfo = Dns.GetHostByAddress(remoteIp);
                    string hostName = hostInfo.HostName;

                    if (hostName.EndsWith("trusted.com")) /* BUG: RELIANCE_ON_DNS_LOOKUPS_IN_A_SECURITY_DECISION_ASPNET */
                    {
                        trusted = true;
                        Response.Write("Trusted Address!");
                    }
                }
            }
        }
    }
}