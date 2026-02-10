package testcase.rule.security.SqlInjectionChecker

import org.springframework.stereotype.Controller
import org.springframework.web.bind.annotation.GetMapping
import java.sql.Connection
import java.sql.ResultSet
import java.sql.Statement
import javax.servlet.http.HttpServletRequest

object InterProcedureCase {
	// propagation in callee
	@GetMapping("/sql1")
	fun sql1(request: HttpServletRequest): String {
		val userId = request.getParameter("userId")			// 외부 입력

		val query = selectUserQuery(userId)
		val c: Connection = dataSource.getConnection()
		val rs = c.createStatement().executeQuery(query)	// @violation
		return "sql"
	}

	// propagator, intra file
	fun selectUserQuery(id: String): String {
		return "select * from user where id = $id"
	}

	// sink in callee
	@GetMapping("/sql2")
	fun sql2(request: HttpServletRequest): String {
		val userId = request.getParameter("userId")			// 외부 입력

		val rs = selectGoodUser(userId)						// @violation
		return "sql"
	}

	// sink, intra file
	fun selectGoodUser(id: String): ResultSet {
		val query = "select * from user where id = $id and score >= 90"
		val c: Connection = dataSource.getConnection()
		val rs = c.createStatement().executeQuery(query)
		return rs
	}
}