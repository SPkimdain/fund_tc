package fs;

/**
 * Created with IntelliJ IDEA.
 * User: starblood
 * Date: 12. 11. 22.
 * Time: 오전 11:14
 */
public class BadSinkClazz {
    static void bad_sink(String data) {
        System.out.format(data);
    }
    void bad_sink_printf(String data) {
        System.out.printf(data);
    }
    public void bad_sink_printf(Object data_obj ) throws Throwable
    {
        String data = (String)data_obj;

        if (data != null)
        {
            /* POTENTIAL FLAW: uncontrolled string formatting */
            System.out.printf(data);
        }

    }

}
