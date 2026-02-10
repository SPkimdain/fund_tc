package testcase.rule.security.PathManipulationChecker

import java.io.File
import java.io.FileInputStream
import java.nio.file.Paths
import javax.servlet.http.HttpServletRequest

import org.springframework.core.io.DefaultResourceLoader
import org.springframework.core.io.FileSystemResource
import org.springframework.core.io.ResourceLoader

object TestCase {
	fun violation(request: HttpServletRequest) {
		val name = request.getParameter("name")             // 외부 입력

		val filepath = "/home/user/$name"

		val file1 = File(filepath)                          // @violation
		val file2 = java.io.File("/home/user/$name")        // @violation

		file1.delete()
	}

    fun violation2(request: HttpServletRequest) {
        val name = request.getParameter("name")             // 외부 입력

        val filepath = "/home/user/$name"

        val file1 = FileInputStream(filepath)               // @violation
        val p = Paths.get(filepath)                         // @violation

        file1.delete()
    }

    fun violation3(request: HttpServletRequest) {
        val name = request.getParameter("name")             // 외부 입력

        val filepath = "/home/user/$name"

        val r = FileSystemResource(filepath)               // @violation
    }

    fun violation4(request: HttpServletRequest) {
        val name = request.getParameter("name")             // 외부 입력

        val filepath = "/home/user/$name"

        val r = DefaultResourceLoader().getResource(filepath)        // @violation
    }

	fun good1(request: HttpServletRequest) {
		val name = request.getParameter("name")             // 외부 입력

		val filter = Regex("[./\\\\&]").replace(name, "")
		val filepath = "/home/user/$filter"

		val file1 = File(filepath)                          // good
		file1.delete()
	}

	fun good2(request: HttpServletRequest) {
		val name = request.getParameter("name")             // 외부 입력

		if(Regex("[./\\\\&]").matches(name)) {
			val filepath = "/home/user/$name"

			val file1 = File(filepath)                      // good
			file1.delete()
		}
	}
}