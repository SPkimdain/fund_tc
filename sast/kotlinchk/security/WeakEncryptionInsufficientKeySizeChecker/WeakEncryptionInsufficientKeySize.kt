package testcase.rule.security.WeakEncryption.InsufficientKeySizeChecker

import java.security.KeyPairGenerator

object TestCase {
	fun violation1() : String {
		val keyGen : KeyPairGenerator
		if(true) {
			keyGen = KeyPairGenerator.getInstance("RSA")
			keyGen.initialize(512)					// @violation
		}
		else {
			keyGen = KeyPairGenerator.getInstance("SHA-256")
			keyGen.initialize(512)					// good
		}

		val key = keyGen.generateKeyPair()
		return key.public.toString()
	}

	fun violation2() : String {
		val keyGen = KeyPairGenerator.getInstance("RSA")
		keyGen.initialize(1024 + 1023)				// @violation
		val key = keyGen.generateKeyPair()
		return key.public.toString()
	}

	fun violation3() : String {
		val keyGen = KeyPairGenerator.getInstance("RSA")
		val keySize = 512 + 1024
		keyGen.initialize(keySize)					// @violation
		val key = keyGen.generateKeyPair()
		return key.public.toString()
	}

	fun good1() : String {
		val keyGen = KeyPairGenerator.getInstance("RSA")
		keyGen.initialize(2048)						// good
		val key = keyGen.generateKeyPair()
		return key.public.toString()
	}

	fun good2() : String {
		val keyGen = KeyPairGenerator.getInstance("RSA")
		val keySize = 1023 * 2 + 100
		keyGen.initialize(keySize)					// good
		val key = keyGen.generateKeyPair()
		return key.public.toString()
	}
}