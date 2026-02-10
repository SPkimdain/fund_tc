package testcase.rule.quality.AlwaysFailCastChecker

object TestCase {
    fun violation() {
        var r = 1       // @violation
        r = 2
        println(r)
    }

    fun violation2() {
        var s: String? = null   // @violation
        s = "test"
        println(s)
    }

    fun violation3() {
        val x = 10      // @violation

        println(10)
    }

    fun violation4(b: Boolean) {
        var r = 1

        if (b) {
            println(r)
        }

        r = 2           // @violation
    }

    fun violation5(b: Boolean) {
        var r = 1   // @violation

        if (b) {
            r = 2
        }

        r = 3       // @violation
    }

    fun good(b: Boolean) {
        var r = 1

        if (b) {
            println(r)
        }

        r = 2
        println(r)
    }
}