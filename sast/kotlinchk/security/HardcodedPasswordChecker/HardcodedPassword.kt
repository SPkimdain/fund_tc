package testcase.rule.security.HardcodedPasswordChecker

import java.sql.Connection
import java.sql.DriverManager
import java.util.*

object TestCase {
	fun violation1() {
		val id = "admin"
		val passwd = "a1234567890!@"
		 
		Class.forName("com.mysql.jdbc.Driver").newInstance()
		val connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/", id, passwd)	// @violation
	}

	fun violation2() {
		val id = "admin"
		val passwd = 1234567890
		 
		Class.forName("com.mysql.jdbc.Driver").newInstance()
		val connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/", id, passwd)	// @violation
	}

	fun violation3() {
		val id = "admin"
		val passwd = byteArrayOf(72, 101, 108, 108, 111)
		 
		Class.forName("com.mysql.jdbc.Driver").newInstance()
		val connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/", id, passwd)	// @violation
	}

	fun good() {
		val id = "admin"
		val key = getPassword("../password.ini")
		val passwd = decrypt(key)
		 
		Class.forName("com.mysql.jdbc.Driver").newInstance()
		val connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/", id, passwd)	// good
	}
}