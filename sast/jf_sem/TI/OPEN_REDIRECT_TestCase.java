package ti;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Properties;

/**
 * Writer: Gyuhang Shim
 * Date: 7/19/12
 */
/* OPT : -show_followers */
public class OPEN_REDIRECT_TestCase extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String query = request.getQueryString();
        if (query.contains("url")) { /* BUG */
            String url = request.getParameter("url");
            response.sendRedirect(url); /* BUG 2 */
            response.sendRedirect("open redirect safe"+url); /* BUG 1 */

            url = url.replaceAll("\r", ""); /* BUG */ // NULL_RETURN_STD from getParameter
            response.sendRedirect(url); /* SAFE */
        }
        Properties props = new Properties();
        String taintedURL = props.getProperty("url");
        taintedURL = request.getParameter("url");
        response.sendRedirect(taintedURL); /* BUG 2 */
    }

    int getAnotherInt() {return 2;}
    int getSomeInt() {return getAnotherInt() - 1;};
    String getMaliciousURL(String input) {
        return input + "/attacker/bankaccount/send_money=?ok";
    }
    protected void doGetComplicated(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String query = request.getQueryString();
        if (query.contains("url")) { /* BUG */
            String url;

            if (getSomeInt() > 0) { // go to true branch
                url = getMaliciousURL(request.getParameter("url"));
            } else {
                url = "http://safe.com";
            }
            response.sendRedirect(url); /* BUG 2 */

            url = url.replaceAll("\r", "");
            response.sendRedirect(url); /* SAFE */
        }
    }
}
