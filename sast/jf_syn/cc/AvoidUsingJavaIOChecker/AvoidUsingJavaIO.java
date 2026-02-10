package cc;

import org.xml.sax.SAXException;

import javax.ejb.Stateless;
import javax.swing.text.Document;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import java.io.File;            // @violation
import java.io.IOException;     // @violation
import java.math.BigDecimal;

class AvoidUsingJavaIO {
    public static class Violation {
        @Stateless
        public class InterestRateBean implements InterestRateRemote {
            private Document interestRateXMLDocument = null;
            private File interestRateFile = null;
            public InterestRateBean() {
                try {

                    /* get XML document from the local filesystem */
                    interestRateFile = new File(Constants.INTEREST_RATE_FILE);

                    if (interestRateFile.exists())
                    {
                        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
                        DocumentBuilder db = dbf.newDocumentBuilder();
                        interestRateXMLDocument = (Document) db.parse(interestRateFile);
                    }
                } catch (IOException ex) {
                    // ...
                } catch (ParserConfigurationException e) {
                    e.printStackTrace();
                } catch (SAXException e) {
                    e.printStackTrace();
                }
            }
            public BigDecimal getInterestRate(Integer points) {
                return getInterestRateFromXML(points);
            }
            /* member function to retrieve interest rate from XML document on the local
            file system */
            private BigDecimal getInterestRateFromXML(Integer points) {
                // ...
            }
        }
    }

    public static class Good {
        @Stateless
        public class InterestRateBean implements InterestRateRemote {
            public InterestRateBean() {
            }
            public BigDecimal getInterestRate(Integer points) {
                return getInterestRateFromXMLParser(points);
            }
            /* member function to retrieve interest rate from XML document using an XML
            parser API */
            private BigDecimal getInterestRateFromXMLParser(Integer points) {
                // ...
            }
        }
    }
}