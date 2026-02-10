package testcase.rule.quality.FixedConditionExpressionChecker

object TestCase {
    fun violation(x: Any, b: Boolean) {
        if (true) {             // @violation
            if (false) {        // @violation
                println("1")
            }
        }
        if (!false) {           // @violation
            println("3")
        }

        if (b || true) {        // @violation
            println("4")
        }

        if (false && b) {       // @violation
            println("5")
        }

        if (x === x) {          // @violation
            println("7")
        }

        if ( b || 1 == 2 || 3 == 4 || "a" == "a" && 10 in 1..10 || false) {  // @violation
            println("8")
        }
    }
}