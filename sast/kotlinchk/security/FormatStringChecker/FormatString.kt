package testcase.rule.security.FormatStringChecker

import java.util.*
import javax.servlet.http.HttpServletRequest

object TestCase {
	fun violation(request: HttpServletRequest) {					// args = "%1$tm, %1$te" 또는 "%1$tY"		// 외부 입력
		val input = request.getParameter("input")

		val validDate = Calendar.getInstance()
		validDate[2014, Calendar.OCTOBER] = 14
		if (input == null) {
			println("Please Input Date (YYYY-MM-DD) !!!")
			return
		}
		val text = "$input did not match! HINT: It was issued on %1\$terd of some month"

		val format = String.format(text, validDate)																// @violation

		System.out.printf("$input did not match! HINT: It was issued on %1\$terd of some month", validDate)		// @violation
		System.out.printf(text, validDate)																		// @violation
		System.out.printf(String.format(text, validDate))														// @violation 2
		System.out.print(String.format(text, validDate))														// @violation
		System.out.println(String.format(text, validDate))														// @violation
		print(String.format(text, validDate))																	// @violation
		println(String.format(text, validDate))																	// @violation
		println(format)
	}

	fun good(request: HttpServletRequest) {
		val input = request.getParameter("input")

		val validDate = Calendar.getInstance()
		validDate[2014, Calendar.OCTOBER] = 14
		if (input == null) {
			println("Please Input Date (YYYY-MM-DD) !!!")
			return
		}
		val text = "%s did not match! HINT: It was issued on %1\$terd of some month"

		val format = String.format(text, input, validDate)														// good

		System.out.printf("%s did not match! HINT: It was issued on %1\$terd of some month", input, validDate)	// good
		System.out.printf(text, input, validDate)																// good
		System.out.printf(String.format(text, validDate))														// good
		System.out.print(String.format(text, input, validDate))													// good
		System.out.println(String.format(text, input, validDate))												// good
		print(String.format(text, input, validDate))															// good
		println(String.format(text, input, validDate))															// good
		println(format)
	}
}