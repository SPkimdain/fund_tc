package rl;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Properties;

/**
 * User: starblood
 * Date: 5/21/13
 * Time: 5:27 PM
 */
public class PropertiesTest {
    private Properties props = null;
    public static String antVersion = "1.8.4";

    private synchronized void readProps() throws BuildException {
        if (props == null) {
            String propsFile = System.getProperty("test.txt");
            if (propsFile == null) {
                throw new BuildException("error");
            }

            props = new Properties();

            try {
                props.load(new FileInputStream(propsFile)); /* */ // RESOURCE_INJECTION, PATH_TRAVERSAL
            } catch (IOException e) {
                throw new BuildException("Couldn't load"); /* BUG */ // RESOURCE_LEAK
            }
        }
    }

    private static class BuildException extends Exception {
        public BuildException(String str) {}
    }

    public static synchronized String getAntVersion() throws BuildException {
        if (antVersion == null) {
            try {
                Properties props = new Properties();
                InputStream in =
                        PropertiesTest.class.getResourceAsStream("/org/apache/tools/ant/version.txt");
                props.load(in);
                in.close();

                StringBuffer msg = new StringBuffer();
                msg.append("Apache Ant(TM) version ");
                msg.append(props.getProperty("VERSION"));
                msg.append(" compiled on ");
                msg.append(props.getProperty("DATE"));
                antVersion = msg.toString();
            } catch (IOException ioe) {
                throw new BuildException("Could not load the version information:"); /* BUG */ // Resource Leak
            } catch (NullPointerException npe) {
                throw new BuildException("Could not load the version information.");
            }
        }
        return antVersion;
    }
}
