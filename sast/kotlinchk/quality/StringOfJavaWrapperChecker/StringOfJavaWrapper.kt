package testcase.rule.quality.StringOfJavaWrapperChecker

import java.lang.Integer

object TestCase {
    fun violation(): String {
        return "" + Integer(1)        // @violation
    }

    fun violation2(): String {
        val a = java.lang.Float(1.1).toString()                         // @violation
        val b = "test interpolation ${java.lang.Double(1.3)} string"    // @violation

        return a + b + java.lang.Character('c').toString()              // @violation
    }
}