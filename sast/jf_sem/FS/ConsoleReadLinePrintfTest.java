package fs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created with IntelliJ IDEA.
 * User: starblood
 * Date: 12. 11. 22.
 * Time: 오후 3:19
 */
/* OPT : -show_followers */
public class ConsoleReadLinePrintfTest {
    /*
        CWE134_Uncontrolled_Format_String__console_readLine_printf_01.java
     */
    public void test1() throws Throwable
    {
        String data;

        data = ""; /* Initialize data */

        /* read user input from console with readLine */
        try {
            InputStreamReader isr = new InputStreamReader(System.in, "UTF-8");
            BufferedReader buffread = new BufferedReader(isr);

            /* POTENTIAL FLAW: Read data from the console using readLine() */
            data = buffread.readLine();
        }
        catch( IOException ioe )
        {
            IO.logger.log(Level.WARNING, "Error with stream reading", ioe);
        }
        /* NOTE: Tools may report a flaw here because buffread and isr are not closed.  Unfortunately, closing those will close System.in, which will cause any future attempts to read from the console to fail and throw an exception */

        if (data != null)
        {
            /* POTENTIAL FLAW: uncontrolled string formatting */
            System.out.printf(data); /* BUG */
        }
    }
}
