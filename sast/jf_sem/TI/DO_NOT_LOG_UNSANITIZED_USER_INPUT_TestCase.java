package ti;

import javax.servlet.http.*;
import java.util.logging.Logger;
import java.util.regex.Pattern;

/* OPT : -show_followers */
public class DO_NOT_LOG_UNSANITIZED_USER_INPUT_TestCase extends HttpServlet {
    private static Logger logger = Logger.getLogger("TEST");

    @SuppressWarnings("unchecked")
    public void doPost(HttpServletRequest req, HttpServletResponse res) {
        try {
            String name = req.getParameter("name"); // tainted input has come

            logger.severe("User name:" + name); /* BUG */
        } catch (Exception e) {
            System.out.println("Exception");
        }
    }

    @SuppressWarnings("unchecked")
    public void doPostSafe(HttpServletRequest req, HttpServletResponse res) {
        try {
            String name = req.getParameter("name"); // tainted input has come

            if (Pattern.matches("[A-Za-z0-9_]+", name)) {
                logger.severe("User name:" + name);  /* BUG */ /* TODO should be fixed */
            }
            else {
                logger.severe("User login failed for unauthorized user");
            }
        } catch (Exception e) {
            System.out.println("Exception");
        }
    }
}