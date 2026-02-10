package testcase.rule.security.OpenRedirectChecker

import org.springframework.stereotype.Controller
import org.springframework.web.bind.annotation.GetMapping
import javax.servlet.http.HttpServletRequest
import javax.servlet.http.HttpServletResponse

object TestCase {
	@GetMapping("/redirect1")
	fun violation(request: HttpServletRequest, response: HttpServletResponse) {
		val url = request.getParameter("url")
		response.sendRedirect(url)								// @violation
	}

	@GetMapping("/redirect2")
	fun good(request: HttpServletRequest, response: HttpServletResponse) {
		val url = request.getParameter("url")
		val whitelist = listOf("index.html", "board.html", "write.html")
		if((url in whitelist) && !url.contains("http://")) {	// good
			response.sendRedirect(url)
		}
	}
}