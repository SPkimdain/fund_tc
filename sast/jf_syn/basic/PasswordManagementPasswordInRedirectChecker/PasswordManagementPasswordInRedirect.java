package basic;

import javax.servlet.ServletRequest;
import javax.servlet.http.HttpServletResponse;

public class PasswordManagementPasswordInRedirect {
    private String pw = "passwd";

    public void redirect(ServletRequest request,HttpServletResponse response) throws Exception {
        String usr = request.getParameter("username");
        String pw = request.getParameter("passwd");

        response.sendRedirect("test.jsp?j_uname=" + usr + "&j_pwd=" + pw); // @violation
        pw = request.getParameter(this.pw);
        response.sendRedirect("test.jsp?j_uname=" + usr + "&j_pwd=" + pw); // @violation
        response.sendRedirect("test.jsp?j_uname=" + usr + "&j_pwd=" + request.getParameter("passwd")); // @violation
        response.sendRedirect("test.jsp?j_uname=" + usr + "&j_pwd=" + request.getParameter(this.pw)); // @violation
        response.encodeRedirectURL("test.jsp?j_uname=" + usr + "&j_pwd=" + pw);
    }
}
