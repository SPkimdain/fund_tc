package testcase.rule.security.UncheckedResult

import java.io.InputStream
import java.io.OutputStream
import java.io.Reader

object TestCase {
    fun violation(input: InputStream, output: OutputStream) {
        val buf = ByteArray(1024)
        var n = input.read(buf)     // @violation
        output.write(buf)
        output.flush()
    }

    fun violation2(input: Reader, output: Writer) {
        val buf = CharArray(1024)
        var n = input.read(buf)     // @violation
        output.write(buf)
        output.flush()
    }

    fun safe(input: InputStream, output: OutputStream) {
        val buf = ByteArray(1024)
        var n = input.read(buf)     // good
        while (n != -1) {
            output.write(buf)
            n = input.read(buf)     // good
        }
        output.flush()
    }

    fun safe2(input: Reader, output: Writer) {
        val buf = CharArray(1024)
        var n = input.read(buf)     // good
        while (n > 0) {
            output.write(buf)
            n = input.read(buf)     // good
        }
        output.write(buf)
        output.flush()
    }
}