package testcase.rule.security.WeakPasswordRequirementsChecker

import org.springframework.stereotype.Controller
import org.springframework.web.bind.annotation.GetMapping
import java.util.regex.Matcher
import java.util.regex.Pattern
import javax.servlet.http.HttpServletRequest

object TestCase {
	@GetMapping("/register1")
	fun violation(request: HttpServletRequest): String {
		val id = request.getParameter("id")
		val pass = request.getParameter("pass")

		val userVo = UserVo(id, pass)
		val result = registDAO.regist(userVo)				// @violation
		return "register"
	}

	@GetMapping("/register2")
	fun good(request: HttpServletRequest): String {
		val id = request.getParameter("id")
		val pass = request.getParameter("pass")
		 
		val pattern = Pattern.compile("((?=.*[a-zA-Z])(?=.*[0-9@#$%]). {9,})")
		val matcher = pattern.matcher(pass)
	 
		if(matcher.matches()) {
			val userVo = UserVo(id, pass)
			val result = registDAO.regist(userVO)			// good
		}
		return "register"
	}
}