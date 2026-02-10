package testcase.rule.security.ConstantRandomSeedChecker

import java.util.Random as JRandom
import kotlin.random.Random as KRandom

object TestCase {
    fun test() {
        val r1 = JRandom()
        r1.setSeed(10)              // @violation

        val r2 = JRandom(100L)      // @violation

        val r3 = KRandom(1000L)     // @violation

        val s1 = 1234L

        val r4 = JRandom()
        r4.setSeed(s1)              // @violation

        val r5 = KRandom("sparrow".hashCode())      // @violation
    }
}