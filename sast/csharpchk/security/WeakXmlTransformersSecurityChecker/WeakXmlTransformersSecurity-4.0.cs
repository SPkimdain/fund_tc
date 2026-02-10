using System.Xml;
using System.Xml.XPath;

namespace CSharp
{
	class TestCase
	{
		public void violation1()
		{
			XmlDocument parser = new XmlDocument();							// violation
			parser.LoadXml("xxe.xml");
		}

		public void violation2()
		{
			XmlTextReader reader = new XmlTextReader("xxe.xml");			// violation
			while (reader.Read())
			{
				// ...
			}
		}

		public void violation3()
		{
			XPathDocument doc = new XPathDocument("example.xml");			// violation
			XPathNavigator nav = doc.CreateNavigator();
			string xml = nav.InnerXml.ToString();
		}

		public void good1()
		{
			XmlDocument parser = new XmlDocument();
			parser.XmlResolver = null;										// good
			parser.LoadXml("xxe.xml");
		}

		public void good2()
		{
			XmlTextReader reader = new XmlTextReader("xxe.xml");
			reader.DtdProcessing = DtdProcessing.Prohibit;					// good
			while (reader.Read())
			{
				// ...
			}
		}

		public void good3()
		{
			XmlReader reader = XmlReader.Create("xxe.xml");					// good
			while (reader.Read())
			{
				// ...
			}
		}

		public void good4()
		{
			XmlReader reader = XmlReader.Create("example.xml");
			XPathDocument doc = new XPathDocument(reader);					// good
			XPathNavigator nav = doc.CreateNavigator();
			string xml = nav.InnerXml.ToString();
		}
		XmlReader field_reader = XmlReader.Create("example.xml");

		public void good5()
		{
			XmlReader reader = XmlReader.Create("example.xml");
			XPathDocument doc = new XPathDocument(field_reader);			// good
			XPathNavigator nav = doc.CreateNavigator();
			string xml = nav.InnerXml.ToString();
		}
	}
}
