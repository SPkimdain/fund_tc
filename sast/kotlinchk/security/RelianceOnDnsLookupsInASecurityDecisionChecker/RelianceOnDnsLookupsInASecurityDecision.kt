package testcase.rule.security.RelianceOnDnsLookupsInASecurityDecisionChecker

import java.net.InetAddress
import javax.servlet.http.HttpServletRequest

object TestCase {
	fun violation1(request: HttpServletRequest) : Boolean {
		val ip = request.remoteAddr
		val address = InetAddress.getByName(ip)
		if (address.canonicalHostName.endsWith("trustme.com")) {			// @violation
			return true
		}
		return false
	}

	fun violation2(request: HttpServletRequest) : Boolean {
		val ip = request.remoteAddr
		val address = InetAddress.getByName(ip)
		if (address.canonicalHostName.equals("http://trustme.com")) {		// @violation
			return true
		}
		return false
	}

	fun violation3(request: HttpServletRequest) : Boolean {
		val ip = request.remoteAddr
		val address = InetAddress.getByName(ip)
		if (address.canonicalHostName == "http://trustme.com") {			// @violation
			return true
		}
		return false
	}

	fun good(request: HttpServletRequest) : Boolean {
		val ip = request.remoteAddr
		if (ip == "192.168.0.100") {										// good
			return true
		}
		return false
	}
}