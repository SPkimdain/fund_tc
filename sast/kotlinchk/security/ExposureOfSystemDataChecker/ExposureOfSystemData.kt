package testcase.rule.security.ExposureOfSystemDataChecker

import java.io.File
import java.io.FileReader
import java.io.IOException
import org.slf4j.Logger
import org.slf4j.LoggerFactory

object TestCase {
    val logger: Logger = LoggerFactory.getLogger(TestCase::class)

	fun violation1(fileName: String) {
		try {
			val file = File(fileName)
			val fileReader = FileReader(file)
		} catch (e: IOException) {
			e.printStackTrace()					// @violation
		}
	}

	fun violation2(fileName: String) {
		try {
			val file = File(fileName)
			val fileReader = FileReader(file)
		} catch (e: IOException) {
			print(e)							// @violation
			println("Error: " + e)				// @violation
			println("Error: " + e + " Hello")	// @violation
			println("Error: $e Hello")			// @violation
		}
	}

    fun violation3(fileName: String) {
        try {
            val file = File(fileName)
            val fileReader = FileReader(file)
        } catch (e: IOException) {
            LoggerFactory.getLogger(TestCase::class).error("file reader fail: {}", e)      // @violation
        }
    }

    fun violation4(fileName: String): kotlin.collections.Map<String,String> {
        try {
            val file = File(fileName)
            val fileReader = FileReader(file)
            val br = BufferedReader(fileReader)
            return mapOf("l" to br.readLine())
        } catch (e: IOException) {
            return mapOf("e" to e.message)                                  // @violation
        }
    }

	fun good(fileName: String) {
		try {
			val file = File(fileName)
			val fileReader = FileReader(file)
		} catch (e: IOException) {
            logger.error("IOException")			// good
		}
	}
}