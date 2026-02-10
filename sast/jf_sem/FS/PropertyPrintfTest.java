package fs;

/**
 * Created with IntelliJ IDEA.
 * User: starblood
 * Date: 12. 11. 22.
 * Time: 오후 2:31
 */
/* OPT : -show_followers */
public class PropertyPrintfTest {
    /*
        CWE134_Uncontrolled_Format_String__Property_printf_01.java
     */
    public void test() throws Throwable
    {
        String data;

        /* get system property user.home */
        /* POTENTIAL FLAW: Read data from a system property */
        data = System.getProperty("user.home");

        if (data != null)
        {
            /* POTENTIAL FLAW: uncontrolled string formatting */
            System.out.printf(data); /* */
        }
    }

    /* Inter-class analysis
        CWE134_Uncontrolled_Format_String__Property_printf_51a.java
     */
    public void test2() throws Throwable
    {
        String data;

        /* get system property user.home */
        /* POTENTIAL FLAW: Read data from a system property */
        data = System.getProperty("user.home");

        (new BadSinkClazz()).bad_sink_printf(data); /* */
    }

    /*  Inter-class analysis
        CWE134_Uncontrolled_Format_String__Property_printf_61a.java
     */
    public void test3() throws Throwable
    {
        String data = (new BadSourceClazz()).bad_source();

        if (data != null)
        {
            /* POTENTIAL FLAW: uncontrolled string formatting */
            System.out.printf(data); /* */
        }

    }
    /*  Inter-class analysis
        CWE134_Uncontrolled_Format_String__Property_printf_71a.java
     */
    public void test4() throws Throwable
    {
        String data;

        /* get system property user.home */
        /* POTENTIAL FLAW: Read data from a system property */
        data = System.getProperty("user.home");

        (new BadSinkClazz()).bad_sink_printf((Object)data  ); /* */
    }
}
