//WEAK_XML_TRANSFORMERS_SECURITY
package security;

import javax.servlet.http.HttpServletRequest;
import java.util.Hashtable;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;


public class WeakXmlTransformersSecurity {

    public void test() {
        //...        
        Transformer transformer = TransformerFactory.newInstance().newTransformer();    // @violation
        TransformerFactory factory = TransformerFactory.newInstance();
        Transformer transformer2 = factory.newTransformer();   // @violation

        TransformerFactory factory2 = TransformerFactory.newInstance();
        factory2.setAttribute(XMLConstants.ACCESS_EXTERNAL_DTD, "");
        factory2.setAttribute(XMLConstants.ACCESS_EXTERNAL_STYLESHEET, "");
        Transformer transformer3 = factory2.newTransformer();    /* Safe */
        //...
    }

}