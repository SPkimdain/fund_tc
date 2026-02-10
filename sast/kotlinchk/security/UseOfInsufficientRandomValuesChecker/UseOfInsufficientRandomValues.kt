package testcase.rule.security.UseOfInsufficientRandomValuesChecker

import java.lang.Math
import java.security.SecureRandom
import java.util.Random as JavaRandom
import java.util.concurrent.ThreadLocalRandom
import kotlin.random.Random

object TestCase {
	fun violation1(n: Int) : Int {
		return (Math.random() * n).toInt()			// @violation
	}

	fun violation2(n: Int) : Int {
		val seed = System.currentTimeMillis();
		val random = JavaRandom(seed)               // @violation
		return random.nextInt(n)
	}

    fun violation3() {
        val r1 = ThreadLocalRandom.current().nextInt()  // @violation
        val r2 = Random.nextInt()                       // @violation
    }

	fun good(n: Int) : Int {
		val random = SecureRandom()					// good
		return random.nextInt(n)
	}
}