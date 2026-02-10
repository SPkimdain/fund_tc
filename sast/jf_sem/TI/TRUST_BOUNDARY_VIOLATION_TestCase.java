package ti;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Properties;

public class TRUST_BOUNDARY_VIOLATION_TestCase  {

    public void test1(HttpServletRequest request) {
        try {
            javax.servlet.http.Cookie[] theCookies = request.getCookies();
            String param = "";
            if (theCookies != null) {
                for (javax.servlet.http.Cookie theCookie : theCookies) {
                    if (theCookie.getName().equals("danger")) {
                        param = java.net.URLDecoder.decode(theCookie.getValue(), "UTF-8"); /* BUG */ //RELIANCE_ON_UNTRUSTED_INPUTS_IN_A_SECURITY_DECISION
                        break;
                    }
                }
            }
            request.getSession().setAttribute( param, "danger param"); /* BUG */ //TRUST_BOUNDARY_VIOLATION
        } catch (Exception  e) {
            return;
        }
    }
}