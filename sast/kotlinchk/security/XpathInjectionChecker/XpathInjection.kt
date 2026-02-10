package testcase.rule.security.XpathInjectionChecker

import org.xml.sax.InputSource
import java.io.StringReader
import javax.servlet.http.HttpServletRequest
import javax.xml.parsers.DocumentBuilderFactory
import javax.xml.xpath.XPath
import javax.xml.xpath.XPathConstants
import javax.xml.xpath.XPathExpression
import javax.xml.xpath.XPathFactory

object TestCase {
	fun violation(request: HttpServletRequest) {
		val xml = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" +
				"<users>\n" +
				"    <user>\n" +
				"        <username>admin</username>\n" +
				"        <password>admin123</password>\n" +
				"        <role>admin</role>\n" +
				"    </user>\n" +
				"    <user>\n" +
				"        <username>testest</username>\n" +
				"        <password>testest123</password>\n" +
				"        <role>guest</role>\n" +
				"    </user>\n" +
				"</users>"
	 
		val user = request.getParameter("username") // user = "admin' or ('1' = '1"								// 외부 입력
		val pass = request.getParameter("password") // password = "unknown_passwd') or '"
	 
		val inputXML = InputSource(StringReader(xml))
		val factory = DocumentBuilderFactory.newInstance()
		val builder = factory.newDocumentBuilder()
		val doc = builder.parse(inputXML)
		val xPath = XPathFactory.newInstance().newXPath()
	 
		// expression = "//user[username/text()='admin' or ('1' = '1' and password/text()='unknown_passwd') or '']/role/text()"
		val expr = xPath.compile("//user[username/text()='$user' and password/text()='$pass']/role/text()")		// @violation
		val result = expr.evaluate(doc, XPathConstants.STRING)
		println(result)
	}

	fun good(request: HttpServletRequest) {
		val xml = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" +
				"<users>\n" +
				"    <user>\n" +
				"        <username>admin</username>\n" +
				"        <password>admin123</password>\n" +
				"        <role>admin</role>\n" +
				"    </user>\n" +
				"    <user>\n" +
				"        <username>testest</username>\n" +
				"        <password>testest123</password>\n" +
				"        <role>guest</role>\n" +
				"    </user>\n" +
				"</users>"
	 
		val username = request.getParameter("username") // username = "admin' or ('1' = '1"
		val password = request.getParameter("password") // password = "unknown_passwd') or '"
	 
		val user = Regex("[\'\"]*").replace(username, "")			// 필터를 통해 injection 공격에 자주 이용되는 특수 문자들 제거
		val pass = Regex("[\'\"]*").replace(password, "")
	 
		val inputXML = InputSource(StringReader(xml))
		val factory = DocumentBuilderFactory.newInstance()
		val builder = factory.newDocumentBuilder()
		val doc = builder.parse(inputXML)
		val xPath = XPathFactory.newInstance().newXPath()
	 
		// expression = "//user[username/text()='admin or (1 = 1' and password/text()='unknown_passwd) or ']/role/text()"
		val expr = xPath.compile("//user[username/text()='$user' and password/text()='$pass']/role/text()")		// good
		val result = expr.evaluate(doc, XPathConstants.STRING)
		println(result)
	}
}