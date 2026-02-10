package testcase.rule.security.StoreSensitiveToOutOfControlChecker

import android.os.Environment
import password
import java.nio.file.Files
import java.io.File
import java.io.FileOutputStream
import java.io.BufferedWriter

object TestCase {
    fun violation1() {
        val secret_key = "xyz123" // sensitive info
        val fos = FileOutputStream("/sdcard/token.txt") // external path
        fos.write(secret_key.toByteArray())         // @violation
    }

    fun violation2() {
        val password = getUserInput() // sensitive info
        val secret_pw = password.toByteArray()
        File("/storage/emulated/0/pass.txt").writeBytes(secret_pw)        // @violation
    }

    fun violation3() {
        val sdcard = "/mnt/sdcard" // external path
        val writer = File(public_path + "user.txt").bufferedWriter()
        writer.write("password=$password")          // @violation
    }

    fun violation4(public_path: String) { // external path
        val writer = File(public_path + "user.txt").bufferedWriter()
        writer.write("password=$password")          // @violation
    }

    fun violation5(external_path: String) { // external path
        val password = getUserInput() // sensitive info
        Files.writeString(File(external_path + "user.txt"), "password=$password") // @violation
    }

    fun violation6(external_path: String) { // external path
        val password = getUserInput() // sensitive info
        val secret_pw = password.toByteArray()
        Files.write(File(external_path + "user.txt"), secret_pw)   // @violation
    }

    fun violation7() {
        val password = getUserInput() // sensitive info
        val secret_pw = password.toByteArray()
        Files.write(File(Environment.getExternalStoragePublicDirectory(), "user.txt"), secret_pw)   // @violation
    }

    fun violation8() {
        val password = getUserInput() // sensitive info
        val secret_pw = password.toByteArray()
        Files.write(File(Environment.getExternalStorageDirectory() + "/user.txt"), secret_pw)   // @violation
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