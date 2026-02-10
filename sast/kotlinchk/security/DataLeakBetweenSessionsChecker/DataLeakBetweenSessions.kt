package testcase.rule.security.DataLeakBetweenSessionsChecker

import javax.servlet.http.HttpServlet
import javax.servlet.http.HttpServletRequest
import javax.servlet.http.HttpServletResponse

object TestCase {
	class Violation1: HttpServlet() {
		var name: String? = null						// @violation

		override fun doPost(req: HttpServletRequest, res: HttpServletResponse) {
			name = req.getParameter("name")
			println("$name, thanks for visiting!")
		}
	}

	class Violation2: HttpServlet() {
		lateinit var name: String						// @violation

		override fun doPost(req: HttpServletRequest, res: HttpServletResponse) {
			name = req.getParameter("name")
			println("$name, thanks for visiting!")
		}
	}

	class Good1: HttpServlet() {
		override fun doPost(req: HttpServletRequest, res: HttpServletResponse) {
			var name: String? = null					// good
			name = req.getParameter("name")
			println("$name, thanks for visiting!")
		}
	}

	class Good2: HttpServlet() {
		override fun doPost(req: HttpServletRequest, res: HttpServletResponse) {
			var name = req.getParameter("name")			// good
			println("$name, thanks for visiting!")
		}
	}

	class Good3: HttpServlet() {
		override fun doPost(req: HttpServletRequest, res: HttpServletResponse) {
			val name = req.getParameter("name")			// good
			println("$name, thanks for visiting!")
		}
	}

	class Good4: HttpServlet {
		class Good4_1: Iterable {
			var name: String? = null					// good

			override fun doPost(req: HttpServletRequest, res: HttpServletResponse) {
				name = req.getParameter("name")
				println("$name, thanks for visiting!")
			}
		}
	}

	class Good5 {
		var name: String? = null						// good

		override fun doPost(req: HttpServletRequest, res: HttpServletResponse) {
			name = req.getParameter("name")
			println("$name, thanks for visiting!")
		}
	}
}