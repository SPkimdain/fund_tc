using System.Xml;
using System.Xml.XPath;

namespace CSharp
{
    class TestCase
    {
        public void violation1()
        {
            XmlTextReader reader = new XmlTextReader("xxe.xml");            // violation       // .NET Framework < 4.5.2
            while (reader.Read())
            {
                // ...
            }
        }

        public void good1()
        {
            XmlTextReader reader = new XmlTextReader("xxe.xml");
            reader.ProhibitDtd = true;                                      // good             // .NET Framework < 4.0
            while (reader.Read())
            {
                // ...
            }
        }
    }
}