package testcase.rule.security.SqlInjectionChecker

import org.springframework.stereotype.Controller
import org.springframework.web.bind.annotation.GetMapping
import java.sql.Connection
import java.sql.ResultSet
import java.sql.Statement
import javax.servlet.http.HttpServletRequest

object InterFileCase {
	// propagation in foreign callee
	@GetMapping("/sql3")
	fun sql3(request: HttpServletRequest): String {
		val userId = request.getParameter("userId")						// 외부 입력

		val query = InterProcedureCase.selectUserQuery(userId)
		val c: Connection = dataSource.getConnection()
		val rs = c.createStatement().executeQuery(query)				// @violation
		return "sql"
	}

	@GetMapping("/sql4")
	fun sql4(request: HttpServletRequest): String {
		val userId = request.getParameter("userId")						// 외부 입력

		val rs = InterProcedureCase.selectGoodUser(userId)				// @violation
		return "sql"
	}
}