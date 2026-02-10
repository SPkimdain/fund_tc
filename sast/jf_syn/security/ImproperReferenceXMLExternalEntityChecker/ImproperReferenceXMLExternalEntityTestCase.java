import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;
import org.w3c.dom.Document;
import org.dom4j.io.SAXReader;
import org.jdom2.input.SAXBuilder;

import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.XMLConstants;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import java.io.FileInputStream;
import java.io.IOException;
import javax.xml.stream.XMLInputFactory;
import javax.xml.transform.TransformerFactory;
import javax.xml.validation.SchemaFactory;

public class ImproperReferenceXMLExternalEntityTestCase {

    public void badTestCase1() throws ParserConfigurationException, IOException, SAXException {
        DocumentBuilderFactory DBFactory = DocumentBuilderFactory.newInstance();    // @violation
        //DBFactory.setFeature("http://apache.org/xml/features/disallow-doctype-decl", true);
        //DBFactory.setFeature("http://xml.org/sax/features/external-general-entities", false);
        //DBFactory.setFeature("http://xml.org/sax/features/external-parameter-entities", false);
        //DBFactory.setAttribute(XMLConstants.ACCESS_EXTERNAL_DTD, "");
        //DBFactory.setAttribute(XMLConstants.ACCESS_EXTERNAL_SCHEMA, "");
        //DBFactory.setXIncludeAware(false);
        //DBFactory.setExpandEntityReferences(false);

        DocumentBuilder db = DBFactory.newDocumentBuilder();
    }

    public void badTestCase2() throws Exception {
        SAXParserFactory factory = SAXParserFactory.newInstance();  // @violation
//        factory.setFeature("http://apache.org/xml/features/disallow-doctype-decl", true);
//        factory.setFeature("http://xml.org/sax/features/external-general-entities", false);
//        factory.setFeature("http://xml.org/sax/features/external-parameter-entities", false);
//        SAXParser parser = factory.newSAXParser();
//        parser.setProperty(XMLConstants.ACCESS_EXTERNAL_DTD, "");
//        parser.setProperty(XMLConstants.ACCESS_EXTERNAL_SCHEMA, "");

        SAXParser saxParser = factory.newSAXParser();
    }

    public void badTestCase3() throws XMLStreamException {
        XMLInputFactory factory = XMLInputFactory.newInstance();    // @violation
//        factory.setProperty(XMLInputFactory.SUPPORT_DTD, false);
//        factory.setProperty(XMLInputFactory.IS_SUPPORTING_EXTERNAL_ENTITIES, false);
//        factory.setProperty(XMLConstants.ACCESS_EXTERNAL_DTD, "");
//        factory.setProperty(XMLConstants.ACCESS_EXTERNAL_SCHEMA, "");
        XMLStreamReader reader = factory.createXMLStreamReader(new ByteArrayInputStream(xml.getBytes()));
    }

    public void badTestCase4() throws Exception {
        TransformerFactory transformerFactory = TransformerFactory.newInstance();   // @violation
//        transformerFactory.setAttribute(XMLConstants.ACCESS_EXTERNAL_DTD, "");
//        transformerFactory.setAttribute(XMLConstants.ACCESS_EXTERNAL_STYLESHEET, "");
        Transformer transformer = transformerFactory.newTransformer();
    }

    public void badTestCase5() throws Exception {
        SchemaFactory factory = SchemaFactory.newInstance(XMLConstants.W3C_XML_SCHEMA_NS_URI); // @violation
//        factory.setFeature("http://apache.org/xml/features/disallow-doctype-decl", true);
//        factory.setProperty(XMLConstants.ACCESS_EXTERNAL_DTD, "");
//        factory.setProperty(XMLConstants.ACCESS_EXTERNAL_SCHEMA, "");
        Schema schema = factory.newSchema(schemaPath);
    }

    public void badTestCase6(Reader reader) throws DocumentException {
        SAXReader saxReader = new SAXReader();  // @violation
        //saxReader.setFeature("http://apache.org/xml/features/disallow-doctype-decl", true);
        Document document = saxReader.read(reader);
    }

    public void badTestCase7(String serializerInfoXml) throws Exception {
        SAXBuilder builder = new SAXBuilder();  // @violation
//        builder.setProperty(XMLConstants.ACCESS_EXTERNAL_DTD, "");
//        builder.setProperty(XMLConstants.ACCESS_EXTERNAL_SCHEMA, "");
        Document doc = builder.build(new StringReader(serializerInfoXml));
    }
}
