package testcase.rule.security.HardCoded.CryptographicKeyChecker

import io.jsonwebtoken.Jwts
import io.jsonwebtoken.SignatureAlgorithm
import javax.crypto.Cipher
import javax.crypto.spec.SecretKeySpec
import org.apache.commons.codec.digest.HmacUtils
import org.jasypt.encryption.pbe.StandardPBEStringEncryptor

object TestCase {
	fun violation1(text: String): String {
		val key = "22df3023sf~2;asn!@#/>as"
		val bToEncrypt = text.toByteArray()
		val sKeySpec = SecretKeySpec(key.toByteArray(), "AES")				// @violation
		val aesCipher = Cipher.getInstance ("AES")
		aesCipher.init(Cipher.ENCRYPT_MODE, sKeySpec)
		val bCipherText = aesCipher.doFinal(bToEncrypt)
		return String(bCipherText)
	}

	fun violation2(text: String): String {
		val key = byteArrayOf(72, 101, 108, 108, 111)
		val bToEncrypt = text.toByteArray()
		val sKeySpec = SecretKeySpec(key, "AES")							// @violation
		val aesCipher = Cipher.getInstance ("AES")
		aesCipher.init(Cipher.ENCRYPT_MODE, sKeySpec)
		val bCipherText = aesCipher.doFinal(bToEncrypt)
		return String(bCipherText)
	}

    fun violation3() {
        val key1 = byteArrayOf(72, 101, 108, 108, 111)
        val key2 = "very-bad-hard-coded-key"
        val key3 = key2.toByteArray()

        Jwts.builder()
            .signWith(SignatureAlgorithm.HS256, key1)  // @violation
            .build()

        Jwts.builder()
            .signWith(SignatureAlgorithm.HS256, key2)  // @violation
            .build()

        Jwts.builder()
            .signWith(SignatureAlgorithm.HS256, key3)  // @violation
            .build()
    }

    fun violation4() {
        val key1 = byteArrayOf(72, 101, 108, 108, 111)
        val key2 = "very-bad-hard-coded-key"
        val key3 = key2.toByteArray()

        HmacUtils(HmacAlgorithms.HMAC_SHA_224, key1)    // @violation
        HmacUtils(HmacAlgorithms.HMAC_SHA_224, key2)    // @violation
        HmacUtils(HmacAlgorithms.HMAC_SHA_224, key3)    // @violation
    }

    fun violation5() {
        val key1 = byteArrayOf(72, 101, 108, 108, 111)
        val key2 = "very-bad-hard-coded-key"
        val key3 = key2.toByteArray()

        val encr = StandardPBEStringEncryptor()
        encr.setPassword(key2)                      // @violation
    }

	fun good(text: String) {
		val key : String = getPassword("../key.ini")
		val decryptedKey = decrypt(key)
		val bToEncrypt = text.toByteArray()
		val sKeySpec = SecretKeySpec(decryptedKey.toByteArray(), "AES")		// good
		val aesCipher = Cipher.getInstance ("AES")
		aesCipher.init(Cipher.ENCRYPT_MODE, sKeySpec)
		val bCipherText = aesCipher.doFinal(bToEncrypt)
		return String(bCipherText)
	}
}