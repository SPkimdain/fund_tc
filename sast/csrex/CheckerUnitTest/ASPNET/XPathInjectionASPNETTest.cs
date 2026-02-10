/* WITH_CHECKERS : XPATH_INJECTION_ASPNET */

using System;
using System.Xml;
using System.Xml.Schema;
using System.Xml.XPath;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
namespace MyVulnerableWebsite
{
    public partial class XPathValidation : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        static void OnClick_Good(object sender, EventArgs e)
        {
            try
            {
                XmlReaderSettings settings = new XmlReaderSettings();
                XmlReader reader = XmlReader.Create("test.xml", settings);
                XmlDocument document = new XmlDocument();
                document.Load(reader);

                XPathNavigator navigator = document.CreateNavigator();

                XPathExpression expr = DynamicContext.Compile("/accounts/account[@acctID=$acctID]/email/text()");
                DynamicContext ctx = new DynamicContext();
                ctx.AddVariable("acctID", AccountIDTextBox.Text);
                expr.SetContext(ctx);

                XPathNodeIterator data = navigator.Select(expr); // SAFE
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }

        static void OnClick_Bad(object sender, EventArgs e)
        {
            try
            {
                XmlReaderSettings settings = new XmlReaderSettings();
                XmlReader reader = XmlReader.Create("test.xml", settings);
                XmlDocument document = new XmlDocument();
                document.Load(reader);

                XPathNavigator navigator = document.CreateNavigator();
                string expr = "/accounts/account[acctID=" + AccountIDTextBox.Text + "]/email/text()";

                XPathNodeIterator data = navigator.Select(expr); /* BUG: XPATH_INJECTION_ASPNET */
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
    }
}