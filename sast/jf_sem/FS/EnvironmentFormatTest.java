package fs;

/**
 * Created with IntelliJ IDEA.
 * User: starblood
 * Date: 12. 11. 22.
 * Time: 오전 10:40
 *
 * FORMAT_STRING : Environment Format test case
 */
/* OPT : -show_followers */
public class EnvironmentFormatTest {
    private boolean private_t = true;
    private boolean private_f = false;
    private final int private_final_five = 5;

    /*
        CWE134_Uncontrolled_Format_String__Environment_format_05.java
     */
    public void testFormat1() {
        String data;
        if (private_t) {
            data = System.getenv("ADD"); // source
        } else {
            data = "foo";
        }
        if(private_t) {
            if (data != null) {
                /* POTENTIAL FLAW: uncontrolled string formatting */
                System.out.format(data); /* */
            }
        } else {
            /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
            if (data != null) {
                /* FIX: explicitly defined string formatting */
                System.out.format("%s%n", data); // SAFE
            }
        }
    }

    /*
        CWE134_Uncontrolled_Format_String__Environment_format_06.java
     */
    public void testFormat2() {
        String data;
        if (private_final_five == 5) {
            data = System.getenv("ADD"); // source
        } else {
            data = "foo";
        }
        if(private_final_five == 5) {
            if (data != null) {
                /* POTENTIAL FLAW: uncontrolled string formatting */
                System.out.format(data); /* */
            }
        } else {
            /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
            if (data != null) {
                /* FIX: explicitly defined string formatting */
                System.out.format("%s%n", data); // SAFE : not reach
            }
        }
    }
    /*
        CWE134_Uncontrolled_Format_String__Environment_format_31.java
     */
    public void testFormat3() {
        String data_copy;
        {
            String data;

            data = System.getenv("ADD"); // source
            data_copy = data;
        }
        {
            String data = data_copy;
            if (data != null) {
                /* POTENTIAL FLAW: uncontrolled string formatting */
                System.out.format(data); /* */
            }
        }
    }
    /*
        CWE134_Uncontrolled_Format_String__Environment_format_41.java
        TODO : Support rule grammar
     */
    public void testFormat4(String data) { // data from method parameter is considered danger
        if (data != null) {
            /* POTENTIAL FLAW: uncontrolled string formatting */
            System.out.format(data); // Currently safe
        }

    }
    /*
        inter-class analysis
        CWE134_Uncontrolled_Format_String__Environment_format_51a.java
     */
    public void testFormat5() { // data from method parameter is considered danger
        String data;
        data = System.getenv("ADD");
        if (data != null) {
            /* POTENTIAL FLAW: uncontrolled string formatting */
            BadSinkClazz.bad_sink(data); /* */
        }
    }
    /*
        CWE134_Uncontrolled_Format_String__Environment_printf_01.java
     */
    public void testPrintf1() { // data from method parameter is considered danger
        String data;
        data = System.getenv("ADD");
        if (data != null) {
            /* POTENTIAL FLAW: uncontrolled string formatting */
            System.out.printf(data); /* */
        }
    }

    public void testPrintf2() { // data from method parameter is considered danger
        String data;
        if(IO.static_t)
        {
            /* get environment variable ADD */
            /* POTENTIAL FLAW: Read data from an environment variable */
            data = System.getenv("ADD");
        }
        else {
            /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */

            /* FIX: Use a hardcoded string */
            data = "foo";

        }
        /* INCIDENTAL: CWE 571 Statement is Always True */
        if(IO.static_t)
        {
            if (data != null)
            {
                /* POTENTIAL FLAW: uncontrolled string formatting */
                System.out.printf(data); /* */
            }
        }
        else {
            /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */

            if (data != null)
            {
                /* FIX: explicitly defined string formatting */
                System.out.printf("%s%n", data);
            }

        }
    }
}
