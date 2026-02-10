/* WITH_CHECKERS : XSLT_INJECTION_CSHARP */

using System;
using System.Collections.Generic;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Xml.Xsl;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
namespace MyVulnerableWebsite
{
    public partial class XSLTInjection: System.Web.UI.Page {
        void Bad()
        {
            string xmlUri = Request.QueryString["XML_URI"];
            string xslUri = Request.QueryString["XSL_URI"];

            XslCompiledTransform xslt = new XslCompiledTransform();
            xslt.Load(xslUri);
            xslt.Transform(xmlUri, "output.html"); /* BUG: XSLT_INJECTION_CSHARP */
        }
    }
}