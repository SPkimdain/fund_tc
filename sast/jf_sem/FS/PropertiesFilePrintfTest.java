package fs;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.Properties;

/**
 * Created with IntelliJ IDEA.
 * User: starblood
 * Date: 12. 11. 22.
 * Time: 오후 2:16
 */
/* OPT : -show_followers */
public class PropertiesFilePrintfTest {
    /*
        CWE134_Uncontrolled_Format_String__PropertiesFile_printf_01.java
     */
    public void bad() throws Throwable
    {
        String data;

        data = ""; /* Initialize data */

        /* retrieve the property */
        Properties props = new Properties();
        FileInputStream finstr = null;
        try {
            finstr = new FileInputStream("../common/config.properties");
            props.load(finstr);

            /* POTENTIAL FLAW: Read data from a .properties file */
            data = props.getProperty("data");
        }
        catch( IOException ioe )
        {
            IO.logger.log(Level.WARNING, "Error with stream reading", ioe);
        }
        finally {
            /* Close stream reading object */
            try {
                if( finstr != null )
                {
                    finstr.close();
                }
            }
            catch( IOException ioe )
            {
                IO.logger.log(Level.WARNING, "Error closing FileInputStream", ioe);
            }
        }
        if (data != null)
        {
            /* POTENTIAL FLAW: uncontrolled string formatting */
            System.out.printf(data); /* */
        }
    }
}
