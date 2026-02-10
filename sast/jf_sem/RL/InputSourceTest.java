package rl;

import org.xml.sax.InputSource;

import java.io.IOException;
import java.io.InputStream;
import java.net.URL;

/**
 * Created with IntelliJ IDEA.
 * User: starblood
 * Date: 5/16/13
 * Time: 9:39 AM
 */
public class InputSourceTest {
    public InputSource test(URL url) {
        InputSource source = null;
        try {
            InputStream is = url.openStream();
            if (is != null) {
                source = new InputSource(is);
                String sysid = url.toExternalForm();
                source.setSystemId(sysid);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return source;
    }
}
