package testcase.rule.quality.DivideByZeroChecker

object TestCase {
    fun violation(n: Int) {
        println(10 / n)             // @violation
    }

    fun violation2(n: Long) {
        println(10L / n)            // @violation
    }

    fun violation3() {
        println(10L / 0L)           // @violation
    }

    fun violation4(n: Short) {
        println(10 % n)             // @violation
    }

    fun safe(n: Int) {
        check(n != 0)
        println(10 / n)
    }

    fun safe2(n: Int) {
        require(n != 0)
        println(10 / n)
    }

    fun safe3(n: Int) {
        if (n > 0) {
            println(10 / n)
        }
    }

    fun safe4(n: Int) {
        if (n == 0) {
            return
        }
        println(10 / n)
    }

    fun safe5(n: Int) {
        try {
            println(10 / n)
        } catch (e: ArithmeticException) {
            println("divide by zero! ${e.getMessage}")
        }
    }

    fun safe6(f: Float, d: Double) {
        println(10.0 / f)

        println(10.0 / d)
    }
}