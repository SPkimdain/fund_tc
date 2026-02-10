package testcase.rule.security.CommandInjectionChecker

import com.jcraft.jsch.ChannelExec
import com.jcraft.jsch.JSch
import com.jcraft.jsch.Session
import java.lang.ProcessBuilder
import java.lang.Runtime
import javax.servlet.http.HttpServletRequest
import org.apache.commons.exec.CommandLine
import org.apache.commons.exec.DefaultExecutor
import org.apache.commons.exec.Executor

object TestCase {
	fun violation(request: HttpServletRequest) {
		val command = request.getParameter("command")			// 외부 입력

		val query = "cmd /c $command"

		val runtime = Runtime.getRuntime()
		val process1 = runtime.exec(query)						// @violation
		val process2 = runtime.exec("cmd /c $command")			// @violation
		val process3 = Runtime.getRuntime().exec(query)			// @violation

        val process4 = ProcessBuilder(query)                    // @violation
        val process5 = ProcessBuilder().command(query)          // @violation

        val session = JSch().getSession("test", "test", 23)
        val ce = session.openChannel("exec") as ChannelExec
        ce.setCommand(query)                                    // @violation
        ce.connect()

        val exec: Executor = DefaultExecutor.builder().get();
        val command1 = CommandLine().addArgument(query)         // @violation
        val exitValue = exec.execute(command1)
	}

    fun bad2(request: HttpServletRequest) {
        val command = request.getParameter("command")			// 외부 입력

        val query = "cmd /c $command"


    }

	fun good(request: HttpServletRequest) {
		val command = request.getParameter("command")			// 외부 입력

		val whitelist = listOf("cd", "dir", "git clone")

		if(command in whitelist) {
			val query = "cmd /c $command"

			val runtime = Runtime.getRuntime()
			val process1 = runtime.exec(query)					// good
			val process2 = runtime.exec("cmd /c $command")		// good
			val process3 = Runtime.getRuntime().exec(query)		// good
		}
	}
}