package rl;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.lang.reflect.Constructor;
import java.net.URL;
import java.util.Enumeration;

/**
 * User: starblood
 * Date: 5/14/13
 * Time: 10:22 AM
 * <p/>
 * Resource Leak test case in ProjectHelperRepository.java reported by Klocwork only, not sparrow.
 */
public class URLStreamTest {
    private void collectProjectHelpers() {
        // First, try the system property
        Constructor projectHelper = null;

        // A JDK1.3 'service' ( like in JAXP ). That will plug a helper
        // automatically if in CLASSPATH, with the right META-INF/services.
        try {
            ClassLoader classLoader = Thread.currentThread().getContextClassLoader();
            if (classLoader != null) {
                Enumeration resources = classLoader.getResources("SERVICE_ID");
                while (resources.hasMoreElements()) {
                    URL resource = (URL) resources.nextElement();
                    projectHelper = getProjectHelperByService(resource.openStream()); // Resource allocation
                }
            }

            InputStream systemResource = ClassLoader.getSystemResourceAsStream("SERVICE_ID"); // Resource allocation
            if (systemResource != null) {
                projectHelper = getProjectHelperByService(systemResource);
            }
        } catch (Exception e) {


        }
    } /* BUG 2 */ // Resource Leak, alarms in 2 paths

    private Constructor getProjectHelperByService(InputStream is) {
        try {
            // This code is needed by EBCDIC and other strange systems.
            // It's a fix for bugs reported in xerces
            InputStreamReader isr;
            try {
                isr = new InputStreamReader(is, "UTF-8");
            } catch (java.io.UnsupportedEncodingException e) {
                isr = new InputStreamReader(is);
            }
            BufferedReader rd = new BufferedReader(isr);

            String helperClassName = rd.readLine(); // IOException thrown
            rd.close();

            if (helperClassName != null && !"".equals(helperClassName)) {
                return Class.forName("test").getConstructor(URLStreamTest.class);
            }
        } catch (Exception e) {
        }
        return null;
    }
}
