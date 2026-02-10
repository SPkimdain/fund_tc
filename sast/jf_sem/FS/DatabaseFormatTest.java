package fs;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * Created with IntelliJ IDEA.
 * User: starblood
 * Date: 12. 11. 22.
 * Time: 오후 3:30
 */
/* OPT : -show_followers */
public class DatabaseFormatTest {
    /*
        CWE134_Uncontrolled_Format_String__database_format_01.java
     */
    public void test1() throws Throwable
    {
        String data;

        data = ""; /* Initialize data */

        /* Read data from a database */
        {
            Connection conn = null;
            PreparedStatement statement = null;
            ResultSet rs = null;
            try {
                /* setup the connection */
                conn = IO.getDBConnection();

                /* prepare and execute a (hardcoded) query */
                statement = conn.prepareStatement("select name from users where id=0");
                rs = statement.executeQuery();

                /* POTENTIAL FLAW: Read data from a database query resultset */
                data = rs.getString(1); // SOURCE
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
        }

        if (data != null)
        {
            /* POTENTIAL FLAW: uncontrolled string formatting */
            System.out.format(data); /* BUG */
        }
    }

    public void test2() throws Throwable
    {
        String data;
        /* INCIDENTAL: CWE 571 Statement is Always True */
        if(5==5)
        {
            data = ""; /* Initialize data */
            /* Read data from a database */
            {
                Connection conn = null;
                PreparedStatement statement = null;
                ResultSet rs = null;
                try
                {
                    /* setup the connection */
                    conn = IO.getDBConnection();
                    /* prepare and execute a (hardcoded) query */
                    statement = conn.prepareStatement("select name from users where id=0");
                    rs = statement.executeQuery();
                    /* POTENTIAL FLAW: Read data from a database query resultset */
                    data = rs.getString(1);
                }
                catch( SQLException se )
                {
                    IO.logger.log(Level.WARNING, "Error with SQL statement", se);
                }
                finally
                {
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
            }
        }
        else {
            /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */

            /* FIX: Use a hardcoded string */
            data = "foo";

        }
        /* INCIDENTAL: CWE 571 Statement is Always True */
        if(5==5)
        {
            if (data != null)
            {
                /* POTENTIAL FLAW: uncontrolled string formatting */
                System.out.format(data); /* BUG */
            }
        }
        else {
            /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */

            if (data != null)
            {
                /* FIX: explicitly defined string formatting */
                System.out.format("%s%n", data);
            }

        }

    }
}
