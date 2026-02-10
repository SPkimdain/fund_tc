package testcase.rule.quality.DoNotUseNotNullAssertionOperatorChecker

import java.util.regex.Matcher
import java.util.regex.Pattern

object TestCase {
	fun violation() {
		val num: Int? = convertInteger("1234a")		// return null
		val castNum = num!!.toDouble()				// @violation
	}

	fun good() {
		val num: Int? = convertInteger("1234a")		// return null
		val castNum = num?.toDouble()				// good
	}

	fun convertInteger(number: String) : Int? {
		val pattern = Pattern.compile("^[0-9]+$")
		val matcher = pattern.matcher(number)
		return  if(matcher.matches()) Integer.parseInt(number)
		else null
	}
}