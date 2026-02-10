import java.io.*;
import java.net.*;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import javax.xml.crypto.dsig.*;
import javax.xml.crypto.dsig.dom.DOMValidateContext;
import javax.xml.parsers.DocumentBuilder;
import org.w3c.dom.Document;
import org.w3c.dom.Element;

public class ImproperSignatureXMLTestCase implements Runnable {
    ImproperSignatureXMLTestCase() throws Exception {
        DocumentBuilder db;
        //...
        Document doc = db.newDocument();
        Element envelope = doc.createElementNS("http://example.org/envelope", "Envelope");
        //...
        KeyPairGenerator kpg = KeyPairGenerator.getInstance("RSA");
        KeyPair kp = kpg.genKeyPair();
        //...

        DOMValidateContext dvc = new DOMValidateContext(kp.getPublic(), envelope.getFirstChild());  // @violation
        dvc.setProperty("org.jcp.xml.dsig.secureValidation", Boolean.FALSE);

        DOMValidateContext dvc2 = new DOMValidateContext(kp.getPublic(), envelope.getFirstChild()); // @violation
        dvc2.setProperty("org.jcp.xml.dsig.secureValidation", false);

        DOMValidateContext dvc3 = new DOMValidateContext(kp.getPublic(), envelope.getFirstChild());
        dvc3.setProperty("org.jcp.xml.dsig.secureValidation", Boolean.TRUE);
        //...
    }
}