package testcase.rule.quality.EmptyCatchBlockChecker

import java.io.BufferedReader
import java.io.File
import java.io.FileReader
import java.io.IOException

object TestCase {
	fun violation(fileName: String) {
		try {
			val bufferedReader = BufferedReader(FileReader(File(fileName)))
		}
		catch (e: IOException) { 			// @violation
			// Empty block ...
		}
	}

	fun good(fileName: String) {
		try {
			val bufferedReader = BufferedReader(FileReader(File(fileName)))
		}
		catch (e: IOException) {
			logger.error("IOException")		// good
		}
	}
}