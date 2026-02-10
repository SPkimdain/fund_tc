package testcase.rule.security.PredictableRandomSeedChecker

import java.lang.ProcessHandle
import java.lang.System
import java.util.Date
import java.util.Random as JRandom
import kotlin.random.Random as KRandom
import kotlin.time.Clock

object TestCase {
    fun test() {
        val s1 = System.currentTimeMillis()
        val r1 = JRandom(System.currentTimeMillis())    // @violation
        r1.setSeed(s1)                                  // @violation

        val r2 = KRandom(s1)                            // @violation

        val s2 = Date.getTime()
        JRandom(s2)                             // @violation

        val now = Clock.System.now()
        KRandom(now.toEpochMilliseconds())      // @violation
        JRandom(now.hashCode())                 // @violation

        val r3 = JRandom()
        val pid = ProcessHandle.current().pid()

        r3.setSeed(pid)                         // @violation
    }
}