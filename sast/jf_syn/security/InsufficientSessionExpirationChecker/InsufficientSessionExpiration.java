package security;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpSession;

public class InsufficientSessionExpiration extends HttpServlet {
    public void noExpiration(HttpSession session) {
        int timeout = -2;

        if (session.isNew()) {
            session.setMaxInactiveInterval(-1); // @violation
        }

        if (session.isNew()) {
            session.setMaxInactiveInterval(timeout); // @violation
        }

        int sessionTimeout = timeout;
        if (session.isNew()) {
            session.setMaxInactiveInterval(sessionTimeout); // @violation
        }

    }
}