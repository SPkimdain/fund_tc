package testcase.rule.quality.ConfusingOperatorPrecedence

object TestCase {
    fun expressions(flag: Boolean, x: Int, y: Int, mask: Int, ready: Boolean, obj: Any) {
        val bad1 = flag && 0x01 == 0 || count > 10         // @violation
        val ok1 = (flag && (0x01 == 0)) || (count > 10)    // good

        val bad2 = x shl y >= 0 && mask != 0                // @violation
        val ok2 = ((x shl y) >= 0) && (mask != 0)           // good

        val bad3 = flag && x < y || ready                   // @violation
        val ok3 = (flag && (x < y)) || ready                // good

        val bad4 = ready || x shl 1 > 3 && flag             // @violation
        val ok4 = ready || (((x shl 1) > 3) && flag)        // good

        val bad5 = flag ?: x < 0 || y > 5                   // @violation
        val ok5 = (flag ?: (x < 0)) || (u > 5)              // good

        val bad6 = x in 1..y && mask > 0                    // @violation
        val ok6 = (x in (1..y)) && (mask > 0)               // good

        val bad7 = obj is String || x == y && flag          // @violation
        val ok7 = (obj is String) || ((x == y) && flag)     // good

        val bad8 = x in 1..y-1 && mask > 0                  // @violation
        val ok8 = x in 1..(y-1)
    }
}