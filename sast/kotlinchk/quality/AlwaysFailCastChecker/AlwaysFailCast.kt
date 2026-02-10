package testcase.rule.quality.AlwaysFailCastChecker

object TestCase {
    fun test() {
        val v1 = 1 as Long      // @violation
        val v2 = "1" as Int     // @violation

        val a: Any = "hi"
        val v3 = a as Int       // @violation
        val v4 = a as? Short    // @violation
        val v5 = a as? String   // good

        val b: Array<Int> = arrayOf(1, 2, 3)
        val v6 = b as Array<String>     // @violation

        val c: IntArray = intArrayOf(1, 2, 3)
        val v7 = b as LongArray         // @violation

        val d: Number = 1
        val v8 = d as Int       // good
    }
}