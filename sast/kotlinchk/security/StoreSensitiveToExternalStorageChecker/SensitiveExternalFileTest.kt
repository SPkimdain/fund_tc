package testcase.rule.security.StoreSensitiveToExternalStorageChecker

import password
import java.nio.file.Files
import java.io.File
import java.io.FileOutputStream
import java.io.BufferedWriter

object TestCase {
    fun violation1() {
        val secret_key = "xyz123" // sensitive info
        val fos = FileOutputStream("/public/token.txt") // external path
        fos.write(secret_key.toByteArray())         // @violation
    }

    fun violation2() {
        val password = getUserInput() // sensitive info
        val secret_pw = password.toByteArray()
        File("/var/www/pass.txt").writeBytes(secret_pw)        // @violation
    }

    fun violation3() {
        val public_dir = "/public/" // external path
        val writer = File(public_dir + "user.txt").bufferedWriter()
        writer.write("password=$password")          // @violation
    }

    fun violation4(public_dir: String) { // external path
        val writer = File(public_dir + "user.txt").bufferedWriter()
        writer.write("password=$password")          // @violation
    }

    fun violation5(public_dir: String) { // external path
        val password = getUserInput() // sensitive info
        Files.writeString(File(public_dir + "user.txt"), "password=$password") // @violation
    }

    fun violation6(public_dir: String) { // external path
        val password = getUserInput() // sensitive info
        val secret_pw = password.toByteArray()
        Files.write(File(public_dir + "user.txt"), secret_pw)   // @violation
    }

    fun safe() {
        val writer = File("/secure/private/user.txt").bufferedWriter() // safe path
        writer.write("password=$password")
    }

    fun safe2() {
        val password = getUserInput() // sensitive info
        val secret_pw = password.toByteArray()
        Files.write(File("/secure/private/user.txt"), secret_pw) // safe path
    }
}
