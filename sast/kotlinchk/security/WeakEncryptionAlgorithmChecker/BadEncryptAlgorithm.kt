package testcase.rule.security.WeakEncryptionAlgorithmChecker

import org.bouncycastle.crypto.digests.RIPEMD160Digest
import java.nio.charset.Charset
import java.security.MessageDigest
import java.security.SecureRandom
import java.security.Signature
import javax.xml.bind.DatatypeConverter
import javax.crypto.Cipher
import javax.crypto.Mac
import javax.crypto.spec.SecretKeySpec

object BadEncryptAlgorithm {
	fun md5Hash(input: String): String {
		val random = SecureRandom.getInstance("SHA256PRNG")
		val salt = random.nextInt().toString()

		val digest = MessageDigest.getInstance("MD5")				// @violation
		digest.update(salt.toByteArray())
		val bytes = digest.digest(input.toByteArray())
		return DatatypeConverter.printHexBinary(bytes).toUpperCase()
	}

	fun sha256Hash(input: String): String {
		val random = SecureRandom.getInstance("SHA256PRNG")
		val salt = random.nextInt().toString()

		val digest = MessageDigest.getInstance("SHA-256")			// good
		digest.update(salt.toByteArray())
		val bytes = digest.digest(input.toByteArray())
		return DatatypeConverter.printHexBinary(bytes).toUpperCase()
	}

    fun ripemdHash(input: String): String {
        val random = SecureRandom.getInstance("SHA256PRNG")
        val salt = random.nextInt().toString()

        val md = RIPEMD160Digest()              // @violation
        md.update(salt.toByteArray())
        md.update(input.toByteArray())

        return ""
    }

	fun complexity(alg: String): MessageDigest {
		return MessageDigest.getInstance(alg)
	}

	fun sha1Hash(input: String): String {
		val random = SecureRandom.getInstance("SHA256PRNG")
		val salt = random.nextInt().toString()

		val a = MessageDigest.getInstance("SHA-1")					// @violation
		val d = complexity("SHA-1")									// bad but cannot detect
		d.update(salt.toByteArray())
		val bytes = d.digest(input.toByteArray())
		return DatatypeConverter.printHexBinary(bytes).toUpperCase()
	}

	fun desCrypt(key: String, input: String): String {
		val algorithm = "DES"
		val cipher = Cipher.getInstance(algorithm)					// @violation
		val spec = SecretKeySpec(key.toByteArray(), algorithm)
		cipher.init(Cipher.ENCRYPT_MODE, spec)
		val cipherTextBytes = cipher.doFinal(input.toByteArray(Charset.defaultCharset()))
		return DatatypeConverter.printHexBinary(cipherTextBytes).toUpperCase()
	}

	fun aesCrypt(key: String, input: String): String {
		val AES = "AES"
		val cipher = Cipher.getInstance(AES)						// good
		val spec = SecretKeySpec(key.toByteArray(), "AES")
		cipher.init(Cipher.ENCRYPT_MODE, spec)
		val cipherTextBytes = cipher.doFinal(input.toByteArray(Charset.defaultCharset()))
		return DatatypeConverter.printHexBinary(cipherTextBytes).toUpperCase()
	}
}