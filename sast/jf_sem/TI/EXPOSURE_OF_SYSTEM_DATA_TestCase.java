package ti;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.SQLException;
import java.sql.DriverManager;
import java.net.InetAddress;

/**
 * Created with IntelliJ IDEA.
 * User: starblood
 * Date: 12. 12. 17.
 * Time: 오전 10:34
 *
 * CWE-209 test case
 */
public class EXPOSURE_OF_SYSTEM_DATA_TestCase {
    Throwable x;
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.getWriter().println("Not in path: " + System.getenv("PATH")); /* BUG 1 */
    }
    public void test(HttpServletRequest request, HttpServletResponse response, String a) throws IOException {

        try {
            DriverManager.getConnection("data-url", "root", a);
            throw new SQLException();
        }
        catch (SQLException e) {
            System.out.println(e.getLocalizedMessage()); /* BUG */
        }
    } /* BUG */

    public void test2() {
        try {
            InetAddress inet = InetAddress.getLocalHost();
            System.out.println(inet.getHostAddress()); /* BUG */
        }
        catch (Exception e) {

        }
    }
}
