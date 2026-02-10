package testcase.rule.security.ToctouRaceConditionChecker

import java.io.*

object TestCase {
	class ViolationThread(type: String) : Thread(type) {
		private val manageType = type

		override fun run() {
			if (manageType == "READ") {
				val f = File("Temp.txt")
				val t = f.exists()
				if (t) {
					for(i in 0..3) {
						val br = BufferedReader(FileReader(f))			// @violation
						br.close()
					}
					val b1 = f.lastModified()							// @violation
					val b2 = f.path										// @violation
					val br = BufferedReader(FileReader(f))				// @violation
					br.close()
				}
			}
			else if (manageType == "DELETE") {
				val f = File("Temp.txt")
				if (f.exists()) {
					f.delete()											// @violation
				}
			}
		}
	}

	class GoodThread(type: String) : Thread(type) {
		private val manageType = type

		override fun run() {
			try {
				if (manageType == "READ") {
					val f = File("Temp.txt")
					if (f.exists()) {
						try {
							for(i in 0..3) {
								val br = BufferedReader(FileReader(f))	// good
								br.close()
							}
							val b1 = f.lastModified()					// good
							val b2 = f.path								// good
							val br = BufferedReader(FileReader(f))		// good
							br.close()
						}
						catch (e: FileNotFoundException) {
							logger.error("FileNotFoundException")
						}
					}
				}
				else if (manageType == "DELETE") {
					val f = File("Temp.txt")
					if (f.exists()) {
						try {
							f.delete()									// good
						}
						catch (e: FileNotFoundException) {
							logger.error("FileNotFoundException")
						}
					}
				}
			}
			catch (e: IOException) {
				logger.error("IOException")
			}
		}
	}

	fun process() {
		val fileAccessThread = ViolationThread("READ")
		val fileDeleteThread = ViolationThread("DELETE")
		fileAccessThread.start()
		fileDeleteThread.start()
	}
}