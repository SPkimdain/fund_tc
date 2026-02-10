package security;

import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;

public class RelianceOnUntrustedInputsInASecurityDecision {
    public void test(HttpServletRequest request) {
        String userRole = null;
        Cookie [] cookies = request.getCookies(); /* TAINTED */
        for (int i = 0; i < cookies.length; i++) {
            Cookie c = cookies[i];
            if (c.getName().equals("role")) { // violation // Semantic taint analysis
                userRole = c.getValue();
            }
            if (Boolean.TRUE.equals(c.getValue())) { // violation // Semantic taint analysis

            }
        }
        Cookie authCookie = new Cookie("authenticated", "1"); // @violation // Syntactic pattern analysis
    }
}