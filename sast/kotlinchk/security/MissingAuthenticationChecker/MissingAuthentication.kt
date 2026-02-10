package testcase.rule.security.MissingAuthenticationChecker

import javax.servlet.http.HttpServletRequest
import javax.servlet.http.HttpSession

object TestCase {
	fun violation(accountNumber: String, balance: Double) {
		val account = BankAccount()
		account.setAccountNumber(accountNumber)
		account.setToPerson("toPerson")
		account.setBalance(balance)
		AccountManager.sendAccount(account)				// @violation
	}

	fun good(request: HttpServletRequest, session: HttpSession, accountNumber: String, balance: Double) {
		val userName = request.getParameter("username")
		val password = request.getParameter("password")
		val sessionUserName = session.getValue("username").toString()
		val sessionPassword = session.getValue("password").toString()
	 
		// 재인증을 통해서 이체 여부를 판단
		if (checkAccount(userName, password, sessionUserName, sessionPassword)) {
			val account = BankAccount()
			account.setAccountNumber(accountNumber)
			account.setToPerson("toPerson")
			account.setBalance(balance)
			AccountManager.sendAccount(account)			// good
		}
	}
}