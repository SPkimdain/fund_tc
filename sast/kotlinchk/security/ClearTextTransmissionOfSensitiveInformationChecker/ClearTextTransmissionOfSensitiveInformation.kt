package testcase.rule.security.ClearTextTransmissionOfSensitiveInformationChecker

import com.google.common.hash.HashCode
import com.google.common.hash.HashFunction
import com.google.common.hash.Hashing
import com.google.common.io.ByteStreams
import org.apache.commons.codec.digest.DigestUtils
import java.io.OutputStream
import java.net.Socket
import java.security.MessageDigest
import java.security.SecureRandom
import javax.servlet.http.HttpServletRequest
import javax.xml.bind.DatatypeConverter

object TestCase {
	fun violation(request : HttpServletRequest, ip: String, port: Int) {
		val socket = Socket(ip, port)
		val passwd = request.getParameter("passwd")

		val outStream = socket.outputStream
		outStream.write(passwd.toByteArray())				// @violation
		socket.close()
	}

	fun good1(request : HttpServletRequest, ip: String, port: Int) {
		val socket = Socket(ip, port)
		val passwd = request.getParameter("passwd")

		val random = SecureRandom.getInstance("SHA256PRNG")
		val salt = random.nextInt().toString()

		val digest = MessageDigest.getInstance("SHA-256")
		digest.update(salt.toByteArray())
		val bytes = digest.digest(passwd.toByteArray())
		val encryptedPasswd = DatatypeConverter.printHexBinary(bytes).toUpperCase()

		val outStream = socket.outputStream
		outStream.write(encryptedPasswd.toByteArray()) 		// good
		socket.close()
	}

	fun good2(request : HttpServletRequest, ip: String, port: Int) {
		val socket = Socket(ip, port)
		val passwd = request.getParameter("passwd")

		val encryptedPasswd = DigestUtils.sha256(passwd)

		val outStream = socket.outputStream
		outStream.write(encryptedPasswd) 					// good
		socket.close()
	}

	fun good3(request : HttpServletRequest, ip: String, port: Int) {
		val socket = Socket(ip, port)
		val passwd = request.getParameter("passwd")

		val encryptedPasswd = ByteStreams.asByteSource(passwd.toByteArray()).hash(Hashing.sha512())

		val outStream = socket.outputStream
		outStream.write(encryptedPasswd) 					// good
		socket.close()
	}

	fun good4(request : HttpServletRequest, ip: String, port: Int) {
		val socket = Socket(ip, port)
		val passwd = request.getParameter("passwd")

		val hashFunction = Hashing.sha512()
		val hashCode = hashFunction.hashBytes(passwd.toByteArray())
		val encryptedPasswd = hashCode.asBytes()

		val outStream = socket.outputStream
		outStream.write(encryptedPasswd) 					// good
		socket.close()
	}
}