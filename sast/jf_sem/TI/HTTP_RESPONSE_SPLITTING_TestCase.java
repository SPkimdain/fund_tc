package ti;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

/**
 * Writer: Gyuhang Shim
 * Date: 5/30/12
 */
/* OPT : -show_followers */
public class HTTP_RESPONSE_SPLITTING_TestCase extends HttpServlet {
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        response.setContentType("text/html");
        // 사용자의 입력정보를 받아서 쿠키를 생성한다.
        String author = request.getParameter("authorName");
        Cookie cookie = new Cookie("replidedAuthor", author); /* BUG */
        cookie.setMaxAge(1000);
        cookie.setSecure(true);
        // HTTP 서비스만 제공하는 경우 사용
        // …
        // 생성된 쿠키를 브라우저에 전송해 저장하도록 한다.
        response.addCookie(cookie);
        RequestDispatcher frd = request.getRequestDispatcher("cookieTest.jsp");
        frd.forward(request, response);

        String field = request.getParameter("field"); // tainted
        String fileName = field;

        response.addHeader("header", field); /* BUG */
        response.sendRedirect(fileName); /* BUG 2 */ // OPEN_REDIRECT
        response.setHeader("Content-Disposition", "attachment; filename=\"" + fileName + "\""); /* BUG */

        String safeFileName = fileName.replace("\r", ""); /* BUG */ //NULL_RETURN_STD
        response.sendRedirect(safeFileName); /* SAFE */
    }

    public void test2(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException{
        String fileName = request.getParameter("fileName");
        if(fileName == null) return;
        response.addHeader("header", fileName); /* BUG */
        String taintFileName = fileName;
        if (taintFileName.indexOf("\r") != -1) {
            response.addHeader("header", taintFileName); /* SAFE */
        }
    }

    public void test3(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException{
        String fileName = request.getParameter("fileName");
        if(fileName == null) return;
        response.addHeader("header", fileName); /* BUG */
        String taintFileName = fileName;
        if (taintFileName.indexOf("\n") != -1) {
            response.addHeader("header", taintFileName); /* SAFE */
        }
    }
    int getSomeInt() {return 2;}
    public void doPostComplicated(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {

        String field = request.getParameter("field");
        String fileName;
        if (getSomeInt() > 2) {
            fileName = java.net.URLEncoder.encode(field, "UTF-8");
        } else {
            fileName = field; // tainted
        }

        response.setHeader("Content-Disposition", "attachment; filename=\"" + fileName + "\""); /* BUG */
    }
}
