using System.Xml;
using System.Xml.XPath;

namespace CSharp
{
	class TestCase
	{
		public void violation1()
		{
			XmlDocument parser = new XmlDocument();                         
			parser.XmlResolver = new XmlUrlResolver();                      // @violation       // .NET Framework 4.5.2+
			parser.LoadXml("xxe.xml");
		}

		public void violation2()
		{
			XmlTextReader reader = new XmlTextReader("xxe.xml");
			reader.XmlResolver = new XmlUrlResolver();                      // @violation       // .NET Framework 4.5.2+
			while (reader.Read())
			{
				// ...
			}
		}

		public void violation3()
		{
			XmlReaderSettings settings = new XmlReaderSettings();
			settings.DtdProcessing = DtdProcessing.Parse;
			settings.XmlResolver = new XmlUrlResolver();
			XmlReader reader = XmlReader.Create("xxe.xml", settings);       // @violation       // .NET Framework 4.5.2+
			while (reader.Read())
			{
				// ...
			}
		}

		public void good1()
		{
			XmlDocument parser = new XmlDocument();                         // good             // .NET Framework 4.5.2+
			parser.LoadXml("xxe.xml");
		}

		public void good2()
		{
			XmlTextReader reader = new XmlTextReader("xxe.xml");            // good             // .NET Framework 4.5.2+
			while (reader.Read())
			{
				// ...
			}
		}

		public void good3()
		{
			XmlReader reader = XmlReader.Create("xxe.xml");                 // good
			while (reader.Read())
			{
				// ...
			}
		}
	}
}
