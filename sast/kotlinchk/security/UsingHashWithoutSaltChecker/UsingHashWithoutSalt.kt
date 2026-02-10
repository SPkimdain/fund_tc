package testcase.rule.security.UsingHashWithoutSaltChecker

import java.security.MessageDigest
import java.security.SecureRandom
import org.apache.commons.codec.digest.DigestUtils

object TestCase {
	fun violation(password: String): ByteArray? {
		val digest = MessageDigest.getInstance("SHA-256")
		digest.reset()
		return digest.digest(password.toByteArray())			// @violation
	}

    fun violation2(password: String): ByteArray? {
        val digest = DigestUtils.getMd5Digest()
        digest.reset()
        return digest.digest(password.toByteArray())            // @violation
    }

    fun violation3(password: String): ByteArray? {
        return DigestUtils.md5(password.toByteArray())          // @violation
    }

	fun good(password: String, salt: ByteArray): ByteArray? {
		val digest = MessageDigest.getInstance("SHA-256")
		digest.reset()
		digest.update(salt)
		return digest.digest(password.toByteArray())			// good
	}

    fun good2(password: String, salt: ByteArray): ByteArray? {
        val digest = DigestUtils.getMd5Digest()
        digest.reset()
        digest.update(salt)
        return digest.digest(password.toByteArray())            // good
    }

    fun good3(password: String): ByteArray? {
        val b1 = DigestUtils.md5(password.toByteArray() + SecureRandom().nextInt(10000).toString().toByteArray()) // good

        val salt2 = SecureRandom().nextInt(10000).toString().toByteArray()
        val b2 = DigestUtils.md5(password.toByteArray() + salt2)            // good

        val salt3 = ByteArray(16)
        SecureRandom.getInstanceStrong().nextBytes(salt3)
        val b3 = DigestUtils.md5(password.toByteArray() + salt3)            // good

        return b3
    }
}