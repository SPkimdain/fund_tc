package testcase.rule.security.IgnoreCaughtException

import kotlinx.coroutines.CoroutineExceptionHandler
import org.springframework.web.bind.annotation.ExceptionHandler

object TestCase {
    fun violation() {
        runCatching  { "123".toInt() }
            .onSuccess { println("success: $it") }
            .onFailure { /* @violation */ }
    }

    fun violation2() {
        val h = CoroutineExceptionHandler { _, _ -> /* @violation */ }
    }

    @ExceptionHandler(java.lang.RuntimeException.class)
    fun violation3(e: java.lang.RuntimeException) { // @violation

    }
}