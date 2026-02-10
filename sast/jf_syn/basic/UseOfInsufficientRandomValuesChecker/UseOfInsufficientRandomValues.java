package basic;

import java.security.SecureRandom;
import java.util.Calendar;
import java.util.Date;
import java.util.Random;

import testcasesupport.*;

import javax.servlet.http.*;
import java.io.*;
import java.security.SecureRandom;

import javax.servlet.http.*;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

import java.util.logging.Logger;

/*
Filename : KRD_208_Insufficiently_Random_Values__console_readLine_2_Random_0101_bad.java
CWEID    : CWE330
sinkname : Random
sinkline : 78,
makedate : 2012 12 24
license  : Copyright KISA.
*/

public class KRD_209_Insufficiently_Random_Values__console_readLine_2_Random_0101_bad extends AbstractTestCase
{

    public void bad() throws Throwable
    {
        String data;

        Logger log_bad = Logger.getLogger("local-logger");

        data = ""; /* init data */

        /* read user input from console with readLine*/
        BufferedReader buffread = null;
        InputStreamReader instrread = null;
        try {
            instrread = new InputStreamReader(System.in, "UTF-8");
            buffread = new BufferedReader(instrread);
            data = buffread.readLine();
        }
        catch( IOException ioe )
        {
            log_bad.warning("Error with stream reading");
        }

        Random rand = new Random();
        /* FLAW: seed is static, making the numbers always occur in the same sequence */
        rand.setSeed(Integer.valueOf(data));
        IO.writeLine("Random int: " + rand.nextInt(100)); // @violation
    }

    /* Below is the main(). It is only used when building this testcase on
       its own for testing or for building a binary to use in testing binary
       analysis tools. It is not used when compiling all the testcases as one
       application, which is how source code analysis tools are tested. */
    public static void main(String[] args) throws ClassNotFoundException,
            InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}

/*
Filename : KRD_208_Insufficiently_Random_Values__Environment_2_Random_0101_bad.java
CWEID    : CWE330
sinkname : Random
sinkline : 37,
makedate : 2012 12 24
license  : Copyright KISA.
*/

public class KRD_209_Insufficiently_Random_Values__Environment_2_Random_0101_bad extends AbstractTestCase
{

    public void bad() throws Throwable
    {
        String data;

        Logger log_bad = Logger.getLogger("local-logger");

        /* get environment variable ADD */
        data = System.getenv("TEST_INT");


        Random rand = new Random();
        /* FLAW: seed is static, making the numbers always occur in the same sequence */
        rand.setSeed(Integer.valueOf(data));
        IO.writeLine("Random int: " + rand.nextInt(100)); // @violation


    }

    /* Below is the main(). It is only used when building this testcase on
       its own for testing or for building a binary to use in testing binary
       analysis tools. It is not used when compiling all the testcases as one
       application, which is how source code analysis tools are tested. */
    public static void main(String[] args) throws ClassNotFoundException,
            InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}

/*
Filename : KRD_208_Insufficiently_Random_Values__fromDB_2_Random_0101_bad.java
CWEID    : CWE330
sinkname : Random
sinkline : 133,
makedate : 2012 12 24
license  : Copyright KISA.
*/

public class KRD_209_Insufficiently_Random_Values__fromDB_2_Random_0101_bad extends AbstractTestCase
{

    public void bad() throws Throwable
    {
        String data;

        Logger log_bad = Logger.getLogger("local-logger");

        data = ""; /* init data */

        Connection conn = null;
        PreparedStatement statement = null;
        ResultSet rs = null;
        BufferedReader buffread = null;
        InputStreamReader instrread = null;
        try {
            /* setup the connection */
            conn = IO.getDBConnection();

            /* prepare and execute a (hardcoded) query */
            statement = conn.prepareStatement("select name from users where id=1");
            rs = statement.executeQuery();
            rs.next();

            data = rs.getString(1);
        }
        catch( SQLException se )
        {
            IO.logger.log(Level.WARNING, "Error with SQL statement", se);
        }
        finally {
                /* Close database objects */
            try {
                if( rs != null )
                {
                    rs.close();
                }
            }
            catch( SQLException se )
            {
                IO.logger.log(Level.WARNING, "Error closing ResultSet", se);
            }

            try {
                if( statement != null )
                {
                    statement.close();
                }
            }
            catch( SQLException se )
            {
                IO.logger.log(Level.WARNING, "Error closing Statement", se);
            }

            try {
                if( conn != null )
                {
                    conn.close();
                }
            }
            catch( SQLException se)
            {
                IO.logger.log(Level.WARNING, "Error closing Connection", se);
            }
        }


        Random rand = new Random();
        /* FLAW: seed is static, making the numbers always occur in the same sequence */
        rand.setSeed(Integer.valueOf(data));
        IO.writeLine("Random int: " + rand.nextInt(100)); // @violation


    }

    /* Below is the main(). It is only used when building this testcase on
       its own for testing or for building a binary to use in testing binary
       analysis tools. It is not used when compiling all the testcases as one
       application, which is how source code analysis tools are tested. */
    public static void main(String[] args) throws ClassNotFoundException,
            InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}
/*
Filename : KRD_208_Insufficiently_Random_Values__fromFile_2_Random_0101_bad.java
CWEID    : CWE330
sinkname : Random
sinkline : 86,
makedate : 2012 12 24
license  : Copyright KISA.
*/

public class KRD_209_Insufficiently_Random_Values__fromFile_2_Random_0101_bad extends AbstractTestCase
{

    public void bad() throws Throwable
    {
        String data;

        Logger log_bad = Logger.getLogger("local-logger");

        data = ""; /* init data */

        File f = new File("C:\\data.txt");
        BufferedReader buffread = null;
        FileInputStream fis = null;
        InputStreamReader isread = null;
        try {
            /* read string from file into data */
            fis = new FileInputStream(f);
            isread = new InputStreamReader(fis, "UTF-8");
            buffread = new BufferedReader(isread);

            data = buffread.readLine(); // This will be reading the first "line" of the file, which
            // could be very long if there are little or no newlines in the file\
        }
        catch( IOException ioe )
        {
            log_bad.warning("Error with stream reading");
        }
        catch( NumberFormatException nfe )
        {
            log_bad.warning("Error with number parsing");
        }
        finally
        {
        /* Close stream reading objects */
            try {
                if( buffread != null )
                {
                    buffread.close();
                }
            }
            catch( IOException ioe )
            {
                IO.logger.log(Level.WARNING, "Error closing BufferedReader", ioe);
            }
            try {
                if( isread != null )
                {
                    isread.close();
                }
            }
            catch( IOException ioe )
            {
                IO.logger.log(Level.WARNING, "Error closing InputStreamReader", ioe);
            }
            try {
                if( fis != null )
                {
                    fis.close();
                }
            }
            catch( IOException ioe )
            {
                IO.logger.log(Level.WARNING, "Error closing FileInputStream", ioe);
            }
        }

        Random rand = new Random();
        /* FLAW: seed is static, making the numbers always occur in the same sequence */
        rand.setSeed(Integer.valueOf(data));
        IO.writeLine("Random int: " + rand.nextInt(100)); // @violation


    }

    /* Below is the main(). It is only used when building this testcase on
       its own for testing or for building a binary to use in testing binary
       analysis tools. It is not used when compiling all the testcases as one
       application, which is how source code analysis tools are tested. */
    public static void main(String[] args) throws ClassNotFoundException,
            InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}

public class UseOfInsufficientRandomValues {
    static Random gr = new Random();

    public void func1() {
        Calendar beginDate = new CalendarChild();
        Calendar endDate = new CalendarChild();

        Random r1 = new Random();
        Random r2 = new Random();
        Random r3 = new Random();
        Random r4;
        Random r5 = new Random();
        Random r6 = new Random(System.currentTimeMillis());

        int seed = 10;

        r2.setSeed(seed + 2);
        r3.setSeed(new Date().getTime());
        gr.setSeed(new Date().getTime());
        r4 = r3;

        int v;
        double random_d = Math.random() % 10; // @violation
        v = r1.nextInt() % 10; // @violation
        v = r2.nextInt() % 10; // @violation
        v = r3.nextInt() % 10;
        v = r4.nextInt() % 10;
        long random_l = ((r5.nextInt() >>> 1) % (endDate.getTimeInMillis() - beginDate.getTimeInMillis() + 1)) + beginDate.getTimeInMillis();
        v = gr.nextInt() % 10;
        v = r6.nextInt() % 10; /* Safe: Seeded in Random Constructor*/
    }

    static {
        int v = gr.nextInt() % 10; // @violation
    }

    public void func2() {
        int v = gr.nextInt() % 10; // @violation
    }

    public void testSecureRandom() {
        SecureRandom random = new SecureRandom();
        System.out.println("Random int: " + random.nextInt(100)); // SAFE
    }

    class CalendarChild extends Calendar {

        @Override
        protected void computeTime() {
            //To change body of implemented methods use File | Settings | File Templates.
        }

        @Override
        protected void computeFields() {
            //To change body of implemented methods use File | Settings | File Templates.
        }

        @Override
        public void add(int field, int amount) {
            //To change body of implemented methods use File | Settings | File Templates.
        }

        @Override
        public void roll(int field, boolean up) {
            //To change body of implemented methods use File | Settings | File Templates.
        }

        @Override
        public int getMinimum(int field) {
            return 0;  //To change body of implemented methods use File | Settings | File Templates.
        }

        @Override
        public int getMaximum(int field) {
            return 0;  //To change body of implemented methods use File | Settings | File Templates.
        }

        @Override
        public int getGreatestMinimum(int field) {
            return 0;  //To change body of implemented methods use File | Settings | File Templates.
        }

        @Override
        public int getLeastMaximum(int field) {
            return 0;  //To change body of implemented methods use File | Settings | File Templates.
        }
    }
}
