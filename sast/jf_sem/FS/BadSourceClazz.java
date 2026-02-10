package fs;

/**
 * Created with IntelliJ IDEA.
 * User: starblood
 * Date: 12. 11. 22.
 * Time: 오후 2:40
 */
public class BadSourceClazz {
    public String bad_source() throws Throwable
    {
        String data;

        /* get system property user.home */
        /* POTENTIAL FLAW: Read data from a system property */
        data = System.getProperty("user.home");

        return data;
    }
}
