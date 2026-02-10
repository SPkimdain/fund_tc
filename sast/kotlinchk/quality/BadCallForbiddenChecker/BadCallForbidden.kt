package testcase.rule.quality.BadCall.ForbiddenChecker

object TestCase {
	fun violation() {
		forbiddenMethod()				// @violation
		Crypto.forbiddenMethod()		// @violation
		val temp = forbiddenMethod()	// @violation
	}

	fun good() {
		allowedMethod()					// good
		Crypto.allowedMethod()			// good
		val temp = allowedMethod()		// good
	}
}