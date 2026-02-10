package testcase.rule.security.ImproperSignatureOfJwtChecker

import io.jsonwebtoken.Jwts
import io.jsonwebtoken.SignatureAlgorithm
import java.io.File
import java.util.Date
import java.util.jar.JarFile
import kotlin.collections.HashMap

object TestCase {
	fun violation1(): String {
		val headers = HashMap<String, Any>()
		headers["typ"] = "JWT"
		headers["alg"] = "HS256"

		val expiredTime = 1000 * 60L
		val now = Date()
		now.time += expiredTime
		val payloads = HashMap<String, Any>()
		payloads["exp"] = now
		payloads["data"] = "hello world!"

		val token = Jwts.builder()				// @violation
			.setHeader(headers)
			.setClaims(payloads)
			.compact()

		return token
	}

	fun violation2(): String {
		val headers = HashMap<String, Any>()
		headers["typ"] = "JWT"
		headers["alg"] = "HS256"

		val expiredTime = 1000 * 60L
		val now = Date()
		now.time += expiredTime
		val payloads = HashMap<String, Any>()
		payloads["exp"] = now
		payloads["data"] = "hello world!"

		val builder = Jwts.builder()
		builder.setHeader(headers)
		builder.setClaims(headers)

		val token = builder.compact()			// @violation

		return token
	}

	fun violation3() {
		val file = File(downlaodedFilePath)
		val jarFile1 = JarFile(file)			// @violation
		val jarFile2 = JarFile(file, false)		// @violation
	}

	fun good1(): String {
		val key = "key~~~"

		val headers = HashMap<String, Any>()
		headers["typ"] = "JWT"
		headers["alg"] = "HS256"

		val expiredTime = 1000 * 60L
		val now = Date()
		now.time += expiredTime
		val payloads = HashMap<String, Any>()
		payloads["exp"] = now
		payloads["data"] = "hello world!"

		val token = Jwts.builder()
			.setHeader(headers)
			.setClaims(payloads)
			.signWith(SignatureAlgorithm.HS256, key.toByteArray())
			.compact()							// good

		return token
	}

	fun good2(): String {
		val key = "key~~~"

		val headers = HashMap<String, Any>()
		headers["typ"] = "JWT"
		headers["alg"] = "HS256"

		val expiredTime = 1000 * 60L
		val now = Date()
		now.time += expiredTime
		val payloads = HashMap<String, Any>()
		payloads["exp"] = now
		payloads["data"] = "hello world!"

		val builder = Jwts.builder()
		builder.setHeader(headers)
		builder.setClaims(headers)
		builder.signWith(SignatureAlgorithm.HS256, key.toByteArray())

		val token = builder.compact()			// good

		return token
	}

	fun good3() {
		val file = File(downlaodedFilePath)
		val jarFile = JarFile(file, true)		// good
	}
}