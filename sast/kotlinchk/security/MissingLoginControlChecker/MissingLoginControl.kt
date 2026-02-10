package testcase.rule.security.MissingLoginControlChecker

object TestCase {
	fun violation1(name: String, password: String): Boolean {
		return login(name, password)							// @violation
	}

	fun violation2(name: String, password: String): Boolean {
		return authenticateUser(name, password)					// @violation
	}

	fun violation3(name: String, password: String): Boolean {
		while (true) {
			authenticateUser(name, password)					// @violation
		}
	}

	fun good1(): Boolean {
		var isValid = false
		var count = 0
		while (!isValid && count < 5) {
			val name = getName()
			val password = getPassword()
			isValid = authenticateUser(name, password)			// good
			count++
		}
		return isValid
	}

	fun good2(name: String, password: String): Boolean {
		var isValid = false
		var count = 0
		for (i in 0 until 5) {
			isValid = authenticateUser(name, password)			// good
			count++

			if(isValid)
				break
		}
		return isValid
	}
}