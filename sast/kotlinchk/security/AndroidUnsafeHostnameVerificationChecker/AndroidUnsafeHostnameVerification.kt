package testcase.rule.security.AndroidUnsafeHostnameVerificationChecker

import java.security.cert.Certificate
import java.security.cert.X509Certificate
import javax.net.ssl.HostnameVerifier
import javax.net.ssl.HttpsURLConnection
import javax.net.ssl.SSLException
import javax.net.ssl.SSLSession

object TestCase {
	fun violation1() {
		val verifier = HostnameVerifier { hostname, session -> true }				// @violation
		HttpsURLConnection.setDefaultHostnameVerifier(verifier)
	}

	fun violation2() {
		val verifier = object : HostnameVerifier {
			override fun verify(hostname: String, session: SSLSession): Boolean {	// @violation
				return true
			}
		}
		HttpsURLConnection.setDefaultHostnameVerifier(verifier)
	}

	fun good1() {
		val verifier = HostnameVerifier { hostname, session ->						// good
			try {
				val certs: Array<Certificate> = session.peerCertificates
				val x509: X509Certificate = certs[0] as X509Certificate
				check(arrayOf<String>(host), x509)
				true
			} catch (e: SSLException) {
				false
			}
		}
		HttpsURLConnection.setDefaultHostnameVerifier(verifier)
	}

	fun good2() {
		val verifier = object : HostnameVerifier {
			override fun verify(hostname: String, session: SSLSession): Boolean {	// good
				return try {
					val certs: Array<Certificate> = session.peerCertificates
					val x509: X509Certificate = certs[0] as X509Certificate
					check(arrayOf<String>(host), x509)
					true
				} catch (e: SSLException) {
					false
				}
			}
		}
		HttpsURLConnection.setDefaultHostnameVerifier(verifier)
	}

	fun good3() {
		val verifier = object : HostnameVerifier {
			override fun verify(hostname: String, session: SSLSession): Boolean {	// good
				try {
					val certs: Array<Certificate> = session.peerCertificates
					val x509: X509Certificate = certs[0] as X509Certificate
					check(arrayOf<String>(host), x509)
					return true
				} catch (e: SSLException) {
					return false
				}
			}
		}
		HttpsURLConnection.setDefaultHostnameVerifier(verifier)
	}
}