package testcase.rule.security.PasswordInCommentChecker

import javax.servlet.http.HttpServletRequest

/* passwd = 94jgk398DSod305jdDGFIO39DJ934mjnKDNGIE34 */									// @violation
// longpatternabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqr	// @violation
// 비밀번호는 abcde0aaa8aaa9baaaaab0bbd!aaa1 이다										// @violation
// long fixed ABCDEFGHIJ0123456789ABCDEFGHIJ0123456789									// @violation
// passwd = a!2@3b4a																	// @violation
/*
 * passwd: a!2@3b4a																		// @violation
 * /*
 * 비밀번호: a!2@3b4a																	// @violation
 password : a!2@3b4a																	// @violation
*/ */
/* password : a!2@3b4a */																// @violation
/*
 * passwd: a!2@3b4a */																	// @violation
/* The comment starts here passwd: a!2@3b4a												// @violation
/* contains a nested comment */ passwd: a!2@3b4a  										// @violation
and ends here. passwd: a!2@3b4a */														// @violation
/* The comment starts here
/* contains a nested comment */ passwd: a!2@3b4a */										// @violation
object TestCase {
	fun violation(request: HttpServletRequest) {
		val passwd = request.getParameter("passwd")
		if(passwd != getPassword()) {		// password : a!2@3b4a						// @violation
			println("Authentication Fail!\n" /* passwd: a!2@3b4a */)					// @violation
		}
		println("Authentication Success!\n")	/* password: a!2@3b4a					// @violation
		* Hello World!!
		*/
	}

	fun good(request: HttpServletRequest) {
		val passwd = request.getParameter("passwd")
		if(passwd != getPassword()) {		// clear									// good
			println("Authentication Fail!\n")
		}
		println("Authentication Success!\n")
	}
}