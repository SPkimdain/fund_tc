package testcase.rule.security.PersistentCookieChecker

import org.springframework.stereotype.Controller
import org.springframework.web.bind.annotation.GetMapping
import javax.servlet.http.Cookie
import javax.servlet.http.HttpServletRequest
import javax.servlet.http.HttpServletResponse

object TestCase {
	@GetMapping("/cookie1")
	fun violation(request: HttpServletRequest, response: HttpServletResponse) {
		val username = request.getParameter("username")
		val passwd = request.getParameter("passwd")
		 
		val cookie = Cookie("passwd", passwd)
		cookie.path = "/"
		cookie.maxAge = 60 * 60 * 24 * 30 * 12			// @violation
		cookie.setMaxAge(60 * 60 * 24 * 30 * 12)		// @violation
		response.addCookie(cookie)
	}

	@GetMapping("/cookie2")
	fun good(request: HttpServletRequest, response: HttpServletResponse) {
		val username = request.getParameter("username")
		val passwd = request.getParameter("passwd")
		
		val cookie = Cookie("passwd", passwd)
		cookie.path = "/"
		cookie.maxAge = 60 * 60							// good
		cookie.setMaxAge(60 * 59)						// good
		response.addCookie(cookie)
	}
}