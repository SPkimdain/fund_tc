/* WITH_CHECKERS : XQUERY_INJECTION_ASPNET */

using System;
using System.Xml;
using System.Xml.Schema;
using System.Xml.XPath;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.IO;
using Saxon.Api;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
namespace MyVulnerableWebsite
{
    public partial class XQueryInjection : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        static string filter(string s)
        {
            return s.Replace("/", "").Replace("[","").Replace("]","").Replace("=","").Replace("'","").Replace("$","");
        }

        static void OnClick_Good(object sender, EventArgs e)
        {
            string user = filter(UserTextBox.Text);     // value tainted -> filtered
            string pass = filter(PasswordField.Value);  // value tainted -> filtered

            string squery =
                    "for $user in doc(users.xml)//user[username='" + user
                    + "'and pass='" + pass
                    + "'] return $user";

            Processor processor = new Processor();
            XdmNode indoc = processor.NewDocumentBuilder().Build(new Uri(Server.MapPath("users.xml")));

            using (StreamReader query = new StreamReader(squery))
            { // tainted value propagated
                XQueryCompiler compiler = processor.NewXQueryCompiler();
                XQueryExecutable exp = compiler.Compile(query.ReadToEnd()); // SAFE
                XQueryEvaluator eval = exp.Load();
                eval.ContextItem = indoc;

                Serializer qout = new Serializer();
                qout.SetOutputProperty(Serializer.METHOD, "xml");
                qout.SetOutputProperty(Serializer.DOCTYPE_PUBLIC, "-//W3C//DTD XHTML 1.0 Strict//EN");
                qout.SetOutputProperty(Serializer.DOCTYPE_SYSTEM, "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd");
                qout.SetOutputProperty(Serializer.INDENT, "yes");
                qout.SetOutputProperty(Serializer.OMIT_XML_DECLARATION, "no");

                qout.SetOutputWriter(Response.Output);
                eval.Run(qout);
            }
        }

        static void OnClick_Bad(object sender, EventArgs e)
        {
            string user = UserTextBox.Text;
            string pass = PasswordField.Value;

            string squery =
                    "for $user in doc(users.xml)//user[username='" + user
                    + "'and pass='" + pass
                    + "'] return $user";    // value tainted

            Processor processor = new Processor();
            XdmNode indoc = processor.NewDocumentBuilder().Build(new Uri(Server.MapPath("users.xml")));

            using (StreamReader query = new StreamReader(squery))
            { // tainted value propagated
                XQueryCompiler compiler = processor.NewXQueryCompiler();
                XQueryExecutable exp = compiler.Compile(query.ReadToEnd()); /* BUG: XQUERY_INJECTION_ASPNET */
                XQueryEvaluator eval = exp.Load();
                eval.ContextItem = indoc;

                Serializer qout = new Serializer();
                qout.SetOutputProperty(Serializer.METHOD, "xml");
                qout.SetOutputProperty(Serializer.DOCTYPE_PUBLIC, "-//W3C//DTD XHTML 1.0 Strict//EN");
                qout.SetOutputProperty(Serializer.DOCTYPE_SYSTEM, "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd");
                qout.SetOutputProperty(Serializer.INDENT, "yes");
                qout.SetOutputProperty(Serializer.OMIT_XML_DECLARATION, "no");

                qout.SetOutputWriter(Response.Output);
                eval.Run(qout);
            }
        }
    }
}