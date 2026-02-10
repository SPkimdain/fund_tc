package testcase.rule.security.StoreInClearTextToCookieChecker

import android.webkit.CookieManager
import org.springframework.http.ResponseCookie
import org.springframework.http.HttpHeaders
import java.time.Duration
import javax.servlet.http.Cookie
import javax.servlet.http.HttpServletRequest
import javax.servlet.http.HttpServletResponse

object TestCase {
    fun violationCookie(request: HttpServletRequest, response: HttpServletResponse) {
        val username = requset.getParameter("username")
        val passwd = request.getParameter("passwd")

        val cookie = Cookie("passwd", passwd)                       // @violation
        cookie.path = "/"
        cookie.maxAge = 3600
        response.addCookie(cookie)
    }

    fun violationHeader(request: HttpServletRequest, response: HttpServletResponse) {
        val username = requset.getParameter("username")
        val passwd = request.getParameter("passwd")

        response.setHeader("Set-Cookie", "password=$password")          // @violation
        response.addHeader("Set-Cookie", "password=$password")          // @violation
    }

    fun violationSpringCookie(request: HttpServletRequest, response: HttpServletResponse) {
        val userId = request.getParameter("username")

        val cookie = ResponseCookie.from("userId", userId)              // @violation
            .httpOnly(true)
            .secure(true)
            .path("/")
            .maxAge(Duration.ofHours(1))
            .build()

        response.setHeader(HttpHeaders.SET_COOKIE, cookie.toString())   // @violation
    }

    fun violationDroid() {
        val pw = getUserInput()

        val cookieManager = CookieManager.getInstance()
        cookieManager.setAcceptCookie(true)

        cookieManager.setCookie("https://example.com", "cookie=$pw")    // @violation
    }

    fun violationHardcoded(response: HttpServletResponse) {
        val cookie1 = Cookie("passwd", "admin123")                          // @violation
        val cookie2 = ResponseCookie.from("userId", "admin")                // @violation
        CookieManager.getInstance().setCookie("https://example.com", "userId=admin")    // @violation

        response.setHeader("Set-Cookie", "password=admin123; HttpOnly")     // @violation
        response.addHeader("Set-Cookie", "password=admin123")               // @violation
    }
}