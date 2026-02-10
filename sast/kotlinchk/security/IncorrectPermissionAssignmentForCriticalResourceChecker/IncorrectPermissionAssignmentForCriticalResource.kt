package testcase.rule.security.IncorrectPermissionAssignmentForCriticalResourceChecker

import java.io.File
import java.io.IOException
import org.apache.hadoop.fs.FileUtil

object TestCase {
	fun violation() {
		try {
			val file = File("/home/setup/system.ini")
			file.setExecutable(true, false)						// @violation
			file.setReadable(true, false)						// @violation
			file.setWritable(true, false)						// @violation

			FileUtil.chmod(file.getAbsolutePath(), "777")		// @violation
		
			Runtime.getRuntime().exec("chmod 777 file")			// @violation

			if (file.createNewFile()) {
				println("File is created!")
			} else {
				println("File already exists.")
			}
		} catch (e : IOException) {
			logger.error("IOException")
		}
	}

	fun good() {
		try {
			val file = File("/home/setup/system.ini")
			file.setReadable(true, false)						// good

			FileUtil.chmod(file.getAbsolutePath(), "755")		// good

			Runtime.getRuntime().exec("chmod 755 file")			// good

			if (file.createNewFile()) {
				println("File is created!")
			} else {
				println("File already exists.")
			}
		} catch (e : IOException) {
			logger.error("IOException")
		}
	}
}