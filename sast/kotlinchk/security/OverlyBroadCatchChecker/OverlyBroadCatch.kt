package testcase.rule.security.OverlyBroadCatchChecker

import java.io.File
import java.io.FileReader
import java.io.IOException

object TestCase {
	fun violation(fileName: String) {
		try {
			val file = File(fileName)
			val fileReader = FileReader(file)
		} catch (e: Exception) {				// @violation
			logger.error("Exception")
		}
	}

	fun good1(fileName: String) {
		try {
			val file = File(fileName)
			val fileReader = FileReader(file)
		} catch (e: IOException) {				// good
			logger.error("IOException")
		}
	}

	fun good2(fileName: String) {
		try {
			val file = File(fileName)
			val fileReader = FileReader(file)
		} catch (e: IOException) {				// good
			logger.error("IOException")
		} catch (e: Exception) {				// good
			logger.error("Exception")
		}
	}
}