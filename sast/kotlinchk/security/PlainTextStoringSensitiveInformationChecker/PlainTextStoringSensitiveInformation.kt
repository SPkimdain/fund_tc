package testcase.rule.security.PlainTextStoringSensitiveInformationChecker

import com.google.common.hash.HashCode
import com.google.common.hash.HashFunction
import com.google.common.hash.Hashing
import com.google.common.io.ByteStreams
import com.google.common.io.Files.asByteSource
import org.apache.commons.codec.digest.DigestUtils
import org.springframework.web.bind.annotation.GetMapping
import java.nio.file.Files
import java.nio.file.Paths
import java.nio.file.StandardOpenOption
import java.security.MessageDigest
import java.security.SecureRandom
import java.sql.Connection
import java.sql.PreparedStatement
import javax.servlet.http.HttpServletRequest
import javax.xml.bind.DatatypeConverter

object TestCase {
	@GetMapping("/insert1")
	fun violation1(request: HttpServletRequest): String {
		val id = request.getParameter("id")
		val passwd = request.getParameter("passwd")
		val name = request.getParameter("name")
		val address = request.getParameter("address")

		val sql = "INSERT INTO user(id, passwd, name, address) values (?, ?, ?, ?)"					// pwd 평문
		val connection: Connection = dataSource.getConnection()
		val stmt = connection.prepareStatement(sql)
		stmt.setString(1, id)
		stmt.setString(2, passwd)																	// @violation
		stmt.setString(2, name)
		stmt.setString(2, address)
		stmt.executeUpdate()
		return "insertDB"
	}

	fun violation2(request: HttpServletRequest) {
		val passwd = request.getParameter("passwd")
		val path = "C:\\passwd.txt"

		Files.write(Paths.get(path), passwd.toByteArray(), StandardOpenOption.CREATE)				// @violation
	}

	@GetMapping("/insert2")
	fun good1(request: HttpServletRequest): String {
		val id = request.getParameter("id")
		val passwd = request.getParameter("passwd")
		val name = request.getParameter("name")
		val address = request.getParameter("address")

		val random = SecureRandom.getInstance("SHA256PRNG")
		val salt = random.nextInt().toString()

		val digest = MessageDigest.getInstance("SHA-256")
		digest.update(salt.toByteArray())
		val bytes = digest.digest(passwd.toByteArray())
		val encryptedPasswd = DatatypeConverter.printHexBinary(bytes).toUpperCase()

		val sql = "INSERT INTO user(id, passwd, name, address) values (?, ?, ?, ?)"					// 암호화된 pwd 값
		val connection: Connection = dataSource.getConnection()
		val stmt = connection.prepareStatement(sql)
		stmt.setString(1, id)
		stmt.setString(2, encryptedPasswd)															// good
		stmt.setString(2, name)
		stmt.setString(2, address)
		stmt.executeUpdate();
		return "insertDB"
	}

	@GetMapping("/insert3")
	fun good2(request: HttpServletRequest): String {
		val id = request.getParameter("id")
		val passwd = request.getParameter("passwd")
		val name = request.getParameter("name")
		val address = request.getParameter("address")

		val encryptedPasswd = DigestUtils.sha256Hex(passwd)

		val sql = "INSERT INTO user(id, passwd, name, address) values (?, ?, ?, ?)"					// 암호화된 pwd 값
		val connection: Connection = dataSource.getConnection()
		val stmt = connection.prepareStatement(sql)
		stmt.setString(1, id)
		stmt.setString(2, encryptedPasswd)															// good
		stmt.setString(2, name)
		stmt.setString(2, address)
		stmt.executeUpdate()
		return "insertDB"
	}

	@GetMapping("/insert4")
	fun good3(request: HttpServletRequest): String {
		val id = request.getParameter("id")
		val passwd = request.getParameter("passwd")
		val name = request.getParameter("name")
		val address = request.getParameter("address")

		val encryptedPasswd = ByteStreams.asByteSource(passwd.toByteArray()).hash(Hashing.sha512())

		val sql = "INSERT INTO user(id, passwd, name, address) values (?, ?, ?, ?)"					// 암호화된 pwd 값
		val connection: Connection = dataSource.getConnection()
		val stmt = connection.prepareStatement(sql)
		stmt.setString(1, id)
		stmt.setString(2, encryptedPasswd)															// good
		stmt.setString(2, name)
		stmt.setString(2, address)
		stmt.executeUpdate()
		return "insertDB"
	}

	@GetMapping("/insert5")
	fun good4(request: HttpServletRequest): String {
		val id = request.getParameter("id")
		val passwd = request.getParameter("passwd")
		val name = request.getParameter("name")
		val address = request.getParameter("address")

		val hashFunction: HashFunction = Hashing.sha512()
		val hashCode: HashCode = hashFunction.hashBytes(passwd.toByteArray())
		val encryptedPasswd = hashCode.asBytes()

		val sql = "INSERT INTO user(id, passwd, name, address) values (?, ?, ?, ?)"					// 암호화된 pwd 값
		val connection: Connection = dataSource.getConnection()
		val stmt = connection.prepareStatement(sql)
		stmt.setString(1, id)
		stmt.setString(2, encryptedPasswd.toString())												// good
		stmt.setString(2, name)
		stmt.setString(2, address)
		stmt.executeUpdate()
		return "insertDB"
	}

	fun good5(request: HttpServletRequest) {
		val passwd = request.getParameter("passwd")
		val path = "C:\\passwd.txt"

		val random = SecureRandom.getInstance("SHA256PRNG")
		val salt = random.nextInt().toString()

		val digest = MessageDigest.getInstance("SHA-256")
		digest.update(salt.toByteArray())
		val bytes = digest.digest(passwd.toByteArray())
		val encryptedPasswd = DatatypeConverter.printHexBinary(bytes).toUpperCase()

		Files.write(Paths.get(path), encryptedPasswd.toByteArray(), StandardOpenOption.CREATE)		// good
	}
}