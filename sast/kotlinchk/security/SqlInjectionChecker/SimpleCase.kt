package testcase.rule.security.SqlInjectionChecker

import org.apache.commons.dbutils.QueryRunner
import org.apache.commons.dbutils.handlers.BeanHandler
import org.springframework.jdbc.core.JdbcTemplate
import org.springframework.stereotype.Controller
import org.springframework.web.bind.annotation.GetMapping
import org.springframework.web.bind.annotation.RequestParam
import jakarta.persistence.EntityManager
import jakarta.persistence.PersistenceContext
import java.sql.* // test import *
//import java.sql.Connection
//import java.sql.ResultSet
//import java.sql.Statement
import javax.servlet.http.HttpServletRequest

object SimpleCase {
	@GetMapping("/sql")
	fun sql(request: HttpServletRequest): String {
		val userId = request.getParameter("userId")											// 외부 입력

		val c: Connection = dataSource.getConnection()
		val rs = c.createStatement().executeQuery("select * from user where id = $userId")	// @violation
		return "sql"
	}

	@GetMapping("/sqlSimple")
	fun sqlSimple(request: HttpServletRequest): String {
		val userId = request.getParameter("userId")											// 외부 입력

		val query = "select * from user where id = $userId"
		val c = Connection()
		val stmt = c.createStatement()
		val rs = stmt.executeQuery(query)													// @violation
		return "sql"
	}

    @GetMapping("/sqlSimple2")
    fun sqlSimple2(request: HttpServletRequest): String {
        val userId = request.getParameter("userId")											// 외부 입력

        val query = "select * from user where id = $userId"

        val jdbcTemplate = JdbcTemplate()
        jdbcTemplate.query(query)                                                           // @violation
        return "sql"
    }

    @GetMapping("/sqlSimple3")
    fun sqlSimple3(request: HttpServletRequest): String {
        val userId = request.getParameter("userId")											// 외부 입력

        val query = "select * from user where id = $userId"

        val runner = QueryRunner()
        val user = runner.query(dataSource.connection, query, BeanHandler(User_Jpa::class.java))    // @violation

        return "sql"
    }

    private lateinit var entityManager: EntityManager
    @PostMapping("/sqlSimple4")
    fun sqlSimple4(@RequestParam input3: String, @RequestParam input4: String)): String {
        val userId = request.getParameter("userId")											// 외부 입력

        val query = entityManager.createQuery( "SELECT u FROM User_Jpa  u WHERE u.uid = '$input3' AND u.password = '$input4'")  // @todo

        return "sql"
    }
}