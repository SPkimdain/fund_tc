package testcase.rule.security.OverlyBroadThrowChecker

import java.io.IOException as RuntimeException

class CustomException(msg: String): Exception(msg) {
}

object TestCase {
    class Error: Exception(msg: String): Exception(msg) {
    }

    fun violation() {
        throw Exception("bad")              // @violation
    }

    fun violation2() {
        throw Error("bad")                  // @violation
    }

    fun good() {
        throw CustomException("good")       // good
    }

    fun good2() {
        throw RuntimeException("bad")       // good (acutal type = IOException)
    }
}