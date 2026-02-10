package security;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

class XMLExternalEntityAttacks {
    private static void receiveXMLStream(InputStream inStream,
                                         DefaultHandler defaultHandler)
            throws ParserConfigurationException, SAXException, IOException {
        SAXParserFactory factory = SAXParserFactory.newInstance();
        SAXParser saxParser = factory.newSAXParser();
        saxParser.parse(inStream, defaultHandler); // @violation

        XMLReader xmlreader = saxParser.getXMLReader();
        RssHandler theRSSHandler = new RssHandler();
        xmlreader.setContentHandler(theRSSHandler);
        InputSource is = new InputSource(url.openStream());
        xmlreader.parse(is); // @violation

    }
}