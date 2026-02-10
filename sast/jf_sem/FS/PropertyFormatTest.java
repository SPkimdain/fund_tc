package fs;

/**
 * Created with IntelliJ IDEA.
 * User: starblood
 * Date: 12. 11. 22.
 * Time: 오후 2:20
 */
/* OPT : -show_followers */
public class PropertyFormatTest {
    /*
        CWE134_Uncontrolled_Format_String__Property_format_01.java
     */
    public void test1() throws Throwable
    {
        String data;

        /* get system property user.home */
        /* POTENTIAL FLAW: Read data from a system property */
        data = System.getProperty("user.home");

        if (data != null)
        {
            /* POTENTIAL FLAW: uncontrolled string formatting */
            System.out.format(data); /* */
        }
    }
    /*
        CWE134_Uncontrolled_Format_String__Property_format_11.java
     */
    public void test2() throws Throwable
    {
        String data;
        if(IO.static_returns_t())
        {
            /* get system property user.home */
            /* POTENTIAL FLAW: Read data from a system property */
            data = System.getProperty("user.home");
        }
        else {
            /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */

            /* FIX: Use a hardcoded string */
            data = "foo";

        }
        if(IO.static_returns_t())
        {
            if (data != null)
            {
                /* POTENTIAL FLAW: uncontrolled string formatting */
                System.out.format(data); /* */
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
    /* The variable below is used to drive control flow in the sink function */
    private boolean bad_private = false;

    public void test3() throws Throwable
    {
        String data;

        /* get system property user.home */
        /* POTENTIAL FLAW: Read data from a system property */
        data = System.getProperty("user.home");

        bad_private = true;
        bad_sink(data );  /* */
    }

    private void bad_sink(String data ) throws Throwable
    {
        if(bad_private)
        {
            if (data != null)
            {
                /* POTENTIAL FLAW: uncontrolled string formatting */
                System.out.format(data);
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
