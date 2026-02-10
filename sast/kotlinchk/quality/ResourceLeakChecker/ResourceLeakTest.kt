package testcase.rule.quality.ResourceLeakChecker

import java.io.FileReader
import java.io.IOException

object TestCase {
    fun violation() {
        var reader = FileReader("test.txt")     // @violation
        try {
            val s = reader.readText()
            print(s)
            reader.close()                      // close must be in finally
        } catch (e: IOException) {
            println("error")
        }
    }

    fun violation2() {
        var reader = FileReader("test.txt")     // @violation
        try {
            val s = reader.readText()
            print(s) // not closed
        } catch (e: IOException) {
            println("error")
        }
    }

    fun safeClose() {
        var reader: FileReader? = null
        try {
            reader = FileReader("test.txt")
            val s = reader.readText()
            print(s) // not closed
        } catch (e: IOException) {
            println("error")
        } finally {
            reader?.close()     // good
        }
    }

    fun safeUse() {
        FileReader("test.txt").use { reader ->
            val text = reader.readText()
            println(text)
        }
    }
}