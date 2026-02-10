package testcase.rule.security.LeftoverDebugCodeChecker

object TestCase {
	fun violation1() {
		println("[DEBUG]\tDATA - ~~~")								// @violation
	}

	fun violation2() {
		val text = "[DEBUG]\tDATA - ~~~"
		println(text)												// @violation
	}

	fun violation3() {
		val text = "[DEBUG]\tDATA - ~~~"
		println("LOG: $text")										// @violation
	}

	fun violation4() {
		val data = byteArrayOf(-0x80, -0x79, 0x00, 0x27, 0x6f)
		println("[DEBUG]\tDATA - ${data.contentToString()}")		// @violation
	}

	fun violation5() {
		val data = byteArrayOf(-0x80, -0x79, 0x00, 0x27, 0x6f)
		val text = "DATA - ${data.contentToString()}"
		printLog("DEBUG", text)										// @violation
	}

	fun violation6() {
		val data = byteArrayOf(-0x80, -0x79, 0x00, 0x27, 0x6f)
		logger.debug("DATA - ${data.contentToString()}")			// @violation
	}

	fun good() {
		val data = byteArrayOf(-0x80, -0x79, 0x00, 0x27, 0x6f)
		// delete debug code										// good
	}
}

fun main() {
	val data = byteArrayOf(-0x80, -0x79, 0x00, 0x27, 0x6f)			// If you don't check the main method
	println("[DEBUG]\tDATA - ${data.contentToString()}")			// good
	logger.debug("DATA - ${data.contentToString()}")				// good
}