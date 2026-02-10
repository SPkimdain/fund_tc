package ti;

import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;

/**
 * Writer: Gyuhang Shim
 * Date: 9/18/12
 */
/* OPT : -show_followers */
public class RELIANCE_ON_UNTRUSTED_INPUTS_IN_A_SECURITY_DECISION_TestCase {
    /*
        source: #RETURN of #METHOD javax.servlet.http.HttpServletRequest.getCookies()
        sink:   #TAINT_INVOKED_BY #METHOD javax.servlet.http.Cookie.getValue()
     */
    public void test(HttpServletRequest request) {
        String userRole = null;
        Cookie[] cookies = request.getCookies(); /* TAINTED */
        for (int i = 0; i < cookies.length; i++) {
            Cookie c = cookies[i];
            if (c.getName().equals("role")) {
                userRole = c.getValue(); /* BUG */
            }
        }
    }

    /*
        source: #RETURN of #METHOD javax.servlet.http.HttpServletRequest.getCookies()
        sink:   1. #TAINT_INVOKED_BY #METHOD javax.servlet.http.Cookie.getValue()
                2. #PARAM 1 of #METHOD java.lang.Boolean.equals(java.lang.Object)
     */
    public void test2(HttpServletRequest request) {
        String userRole = null;
        Cookie[] cookies = request.getCookies(); /* TAINTED */
        for (int i = 0; i < cookies.length; i++) {
            Cookie c = cookies[i];
            if (Boolean.TRUE.equals(c.getValue())) { /* BUG 2 */ // sink#1 + sink#2

            }
        }
    }

    /*
        source: #RETURN of #METHOD javax.servlet.http.HttpServletRequest.getParameter()
        sink:   #TAINT_INVOKED_BY #METHOD javax.servlet.http.Cookie.getValue()
     */
    public void test3(HttpServletRequest request) {
        String name = request.getParameter("name");
        String value = "value";

        Cookie cookie = new Cookie(name, value);

        String userRole = cookie.getValue(); /* BUG */

    }

    /*
        source: #RETURN of #METHOD javax.servlet.http.HttpServletRequest.getParameter()
        sinks:  1. #TAINT_INVOKED_BY #METHOD java.lang.equals(java.lang.String) with_args ("authentication")
                2. #TAINT_INVOKED_BY #METHOD java.lang.equals(java.lang.String) with_args ("auth")
     */
    public void test4(HttpServletRequest request) {
        String name = request.getParameter("name"); // tainted
        String value = "value";

        Cookie cookie = new Cookie(name, value); // tainted Cookie object

        if (cookie.getName().equals("authentication")) { /* BUG */

        }

        if (cookie.getName().equals("role")) { /* SAFE */

        }

        if (cookie.getName().equals("auth")) { /* BUG */

        }
    }
}
