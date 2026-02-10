package testcase.rule.security.StoreInClearTextToFileChecker

import password
import java.io.File
import java.io.FileOutputStream
import java.io.BufferedWriter

object TestCase {
    fun violation1() {
        val secret_key = "xyz123" // sensitive info
        val fos = FileOutputStream("creds.dat")
        fos.write(secret_key.toByteArray())         // @violation
    }

    fun violation2() {
        val password = getUserInput() // sensitive info
        val secret_pw = password.toByteArray()
        File("pw.txt").writeBytes(secret_pw)        // @violation
    }

    fun violation3() {
        val writer = File("user.txt").bufferedWriter()
        writer.write("password=$password")          // @violation
    }
}
