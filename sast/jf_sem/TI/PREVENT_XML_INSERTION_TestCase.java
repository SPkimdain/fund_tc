package ti;

import org.xml.sax.*;
import org.xml.sax.helpers.DefaultHandler;

import javax.xml.XMLConstants;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import javax.xml.transform.stream.StreamSource;
import javax.xml.validation.Schema;
import javax.xml.validation.SchemaFactory;
import java.io.*;

public class PREVENT_XML_INSERTION_TestCase {
    public static void main(String[] args) throws IOException {
        violation("attack");
        good("attack");
    }

    private static void violation(final String userInput) throws IOException {
        final BufferedOutputStream outStream = new BufferedOutputStream(new FileOutputStream("out.xml"));
        String xmlString = "<item>\n<description>Widget</description>\n"
                + "<price>500</price>\n" + "<quantity>" + userInput
                + "</quantity></item>";

        outStream.write(xmlString.getBytes());
        outStream.flush();
    }

    private static void good(final String userInput) throws IOException {
        final BufferedOutputStream outStream = new BufferedOutputStream(new FileOutputStream("out.xml"));
        // Write XML string only if quantity is an unsigned integer (count).
        int count = Integer.parseUnsignedInt(userInput);
        String xmlString = "<item>\n<description>Widget</description>\n"
                + "<price>500</price>\n" + "<quantity>"
                + count + "</quantity></item>";

        outStream.write(xmlString.getBytes());
        outStream.flush();
    }
}