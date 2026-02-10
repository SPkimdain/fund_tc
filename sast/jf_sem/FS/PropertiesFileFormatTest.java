package fs;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.Properties;

/**
 * Created with IntelliJ IDEA.
 * User: starblood
 * Date: 12. 11. 22.
 * Time: 오후 2:06
 */
/* OPT : -show_followers */
public class PropertiesFileFormatTest {
    /*
        CWE134_Uncontrolled_Format_String__PropertiesFile_format_01.java
     */
    public void test1() throws Throwable
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
            System.out.format(data); /* */
        }
    }
    /*
        CWE134_Uncontrolled_Format_String__PropertiesFile_format_19.java
     */
    public void test2() throws Throwable
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

        {
            if (data != null)
            {
                /* POTENTIAL FLAW: uncontrolled string formatting */
                System.out.format(data); /* */
            }

        }

        if(true) return; /* INCIDENTAL: CWE 571 Expression is Always True.
          We need the "if(true)" because the Java Language Spec requires that
          unreachable code generate a compiler error */

        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {

            if (data != null)
            {
                /* FIX: explicitly defined string formatting */
                System.out.format("%s%n", data);
            }

        }
    }
}
