package testcase.rule.quality.ReturnInFinally

object TestCase {
    fun violation() {
        try {
            1
        } finally {
            2           // @violation
        }
    }

    fun violation2() {
        try {
            1
        } finally {
            println("hello")
            return 2    // @violation
        }
    }

    fun good() {
        try {
            1
        } finally {
            println("hello")    // good
        }
    }

    fun good2() {
        try {
            println("what?")
        } catch(e: RuntimeException) {
            println("caught")
        } finally {
            println("hello")    // good
        }
    }

    fun good3() {
        try {
            println("what?")
        } catch(e: RuntimeException) {
            println("caught")
        } finally {
            generateSequence(0) { it + 1 }
                .take(5)
                .forEach {
                    println(it)
                    return@forEach  // @violation : good with ignore_labeled option
                }
        }
    }
}