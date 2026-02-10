package ti;

import javax.servlet.ServletRequest;
import javax.servlet.http.Cookie;
import java.net.HttpCookie;

/**
 * Writer: Gyuhang Shim
 * Date: 7/30/12
 */
public class PERSISTENT_COOKIE_TestCase {
    public void makeCookie(ServletRequest request) {
        String maxAge = request.getParameter("maxAge");
        if(maxAge == null) return;
        if (maxAge.matches("[0-9]+")) {
            String sessionID = request.getParameter("sessionID");
            if(sessionID == null) return;
            if (sessionID.matches("[A-Z=0-9a-z]+")) {
                Cookie c = new Cookie("sessionID", sessionID); /* BUG */ // HTTP_RESPONSE_SPLITTING_TestCase
                // 외부 입력이 쿠키 유효한 설정에 그대로 사용 되었다.
                c.setMaxAge(Integer.parseInt(maxAge)); /* BUG */
            }
        }
    }

    public void makeCookie2(ServletRequest request) {
        String maxAge = request.getParameter("maxAge");
        if(maxAge == null) return;
        if (maxAge.matches("[0-9]+")) {
            String sessionID = request.getParameter("sessionID");
            if(sessionID == null) return;
            if (sessionID.matches("[A-Z=0-9a-z]+")) {
                Cookie c = new Cookie("sessionID", sessionID); /* BUG */ // HTTP_RESPONSE_SPLITTING_TestCase
                // 외부 입력이 쿠키 유효한 설정에 그대로 사용 되었다.
                int t = Integer.parseInt(maxAge);
                int t2 = 0;
                if (t > 7200) { // 쿠기의 시간을 재설정
                    t2 = 7200;
                }
                c.setMaxAge(t); /* BUG */
                c.setMaxAge(t2); /* BUG */
            }
        }
    }

    public void makeSafeCookie(ServletRequest request) {
        String maxAge = request.getParameter("maxAge");
        if(maxAge == null) return;
        if (maxAge.matches("[0-9]+")) {
            String sessionID = request.getParameter("sessionID");
            if(sessionID == null) return;
            if (sessionID.matches("[A-Z=0-9a-z]+")) {
                Cookie c = new Cookie("sessionID", sessionID); /* BUG */ // HTTP_RESPONSE_SPLITTING_TestCase
                // 외부 입력이 쿠키 유효한 설정에 그대로 사용 되었다.
                int t = Integer.parseInt(maxAge);
                if (t > 3600) { // 쿠기의 시간을 재설정
                    t = 3600;
                }
                c.setMaxAge(t); /* SAFE */
            }
        }
    }

    public void makeSafeCookie2(ServletRequest request) {
        String maxAge = request.getParameter("maxAge");
        if(maxAge == null) return;
        if (maxAge.matches("[0-9]+")) {
            String sessionID = request.getParameter("sessionID");
            if(sessionID == null) return;
            if (sessionID.matches("[A-Z=0-9a-z]+")) {
                Cookie c = new Cookie("sessionID", sessionID); /* BUG */ // HTTP_RESPONSE_SPLITTING_TestCase
                // 외부 입력이 쿠키 유효한 설정에 그대로 사용 되었다.
                int t = Integer.parseInt(maxAge);
                if (t > 60) { // 쿠기의 시간을 재설정
                    t = 60;
                }
                c.setMaxAge(t); /* SAFE */
            }
        }
    }
    /*
        source : System.getenv()
        sink : Cookie.setMaxAge()
     */
    public void test1(ServletRequest request) {
        String maxAge = request.getParameter("age");//String maxAge = System.getenv("age");
        if (maxAge != null && maxAge.matches("[0-9]+")) {
            String sessionID = request.getParameter("sessionID");
            if(sessionID == null) return;
            if (sessionID.matches("[A-Z=0-9a-z]+")) {
                Cookie c = new Cookie("sessionID", sessionID); /* BUG */ // HTTP_RESPONSE_SPLITTING_TestCase
                // 외부 입력이 쿠키 유효한 설정에 그대로 사용 되었다.
                c.setMaxAge(Integer.parseInt(maxAge)); /* BUG */
            }
        }
    }
    /*
        source : const integer
        sink : HttpCooke.setMaxAge()
     */
    public void test2(ServletRequest request) {
        HttpCookie hc = new HttpCookie("sessionID", "hello");
        hc.setMaxAge(60*60*24*7); /* BUG */
    }
}
