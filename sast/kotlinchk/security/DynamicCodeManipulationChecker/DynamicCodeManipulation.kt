package testcase.rule.security.DynamicCodeManipulationChecker

import javax.script.ScriptEngine
import javax.script.ScriptEngineManager
import javax.servlet.http.HttpServletRequest

object TestCase {
	fun violation(request: HttpServletRequest) {
		val input = request.getParameter("input")

		val manager = ScriptEngineManager()
		val engine = manager.getEngineByName("JavaScript")
		engine.eval(input)							// @violation
	}

	fun good(request: HttpServletRequest) {
		val input = request.getParameter("input")
		
		// Match the input against a whitelist
		if (whiteList.contains(input)) {
			val manager = ScriptEngineManager()
			val engine = manager.getEngineByName("JavaScript")
			engine.eval(input)						// good
		}
	}
}