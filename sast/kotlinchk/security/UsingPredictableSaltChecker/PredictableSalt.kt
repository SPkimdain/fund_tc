package testcase.rule.security.UsingHashWithoutSaltChecker

import java.util.Random
import java.util.UUID
import java.security.MessageDigest
import java.security.SecureRandom
import org.apache.commons.codec.digest.DigestUtils

object TestCase {
    fun violation(password: String): ByteArray? {
        val digest = MessageDigest.getInstance("SHA-256")
        digest.reset()
        digest.update("example_salt".toByteArray())             // @violation
        return digest.digest(password.toByteArray())
    }

    fun violation2(password: String): ByteArray? {
        val digest = DigestUtils.getMd5Digest()
        val salt = 1234.toByte()
        digest.reset()
        digest.update(salt)                                     // @violation
        return digest.digest(password.toByteArray())
    }

    fun violation3(password: String): ByteArray? {
        val b1 = DigestUtils.md5(password.toByteArray() + Random().nextInt(10000).toString().toByteArray()) // @violation

        val salt2 = Random().nextInt(10000).toString().toByteArray()
        val b2 = DigestUtils.md5(password.toByteArray() + salt2)            // @violation

        return b2
    }

    fun violation4(password: String): ByteArray? {
        val digest = DigestUtils.getMd5Digest()
        val salt = java.lang.System.currentTimeMillis().toString().toByteArray()
        digest.reset()
        digest.update(salt)                                                 // @violation
        return digest.digest(password.toByteArray())
    }

    fun violation5(password: String): ByteArray? {
        val digest = DigestUtils.getMd5Digest()
        val salt = UUID.nameUUIDFromBytes(userId.toByteArray()).toString().toByteArray()
        digest.reset()
        digest.update(salt)                                                 // @violation
        return digest.digest(password.toByteArray())
    }

    fun good(password: String, salt: ByteArray): ByteArray? {
        val digest = MessageDigest.getInstance("SHA-256")
        digest.reset()
        digest.update(salt) 			                        // good
        return digest.digest(password.toByteArray())
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