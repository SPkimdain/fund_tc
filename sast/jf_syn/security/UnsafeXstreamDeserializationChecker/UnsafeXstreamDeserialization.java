//UNSAFE_XSTREAM_DESERIALIZATION
package security;

import com.thoughtworks.xstream.*;

public class UnsafeXstreamDeserialization {
    public void testMethod() {
        XStream xstream = new XStream();
        String body = "Body";
        Contact expl = (Contact) xstream.fromXML(body); // @violation
    }
}