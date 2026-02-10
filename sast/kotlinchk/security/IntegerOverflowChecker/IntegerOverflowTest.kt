package testcase.rule.security.IntegerOverflowTest

import javax.servlet.http.HttpServletRequest

object TestCase {
    fun downCastViolation(n: Int) {
        val a: Long = 2_147_483_648L
        val a2: Int = a.toInt()          // @violation

        val b: Int = 32767
        val b2: Short = b.toShort()     // OK
        val b3: Byte = b.toByte()       // @violation
        val b4: Long = b.toLong()       // OK
        val b5: Int = b.toInt()         // OK

        val c: Short = 32780.toShort()  // @violation

        val d: Long = 32780L
        val d2: Short = d.toShort()     // @violation
        val d3: Byte = d.toByte()       // @violation
        val d4: Int = d.toInt()         // OK
        val d5 = d.toLong()             // OK

        n.toShort()                     // @violation
    }

    fun inputViolation(request : HttpServletRequest): Int {
        val dollarStr: String = request.getParameter("deposit")
        val dollar = dollarStr.toInt()
        val approxKrw = dollar * 1500       // @violation

        return approxKrw
    }
}