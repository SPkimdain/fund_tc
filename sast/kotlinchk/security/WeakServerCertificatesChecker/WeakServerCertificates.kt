package testcase.rule.security.WeakServerCertificatesChecker

import java.security.cert.CertificateException
import java.security.cert.X509Certificate
import java.util.logging.Logger
import javax.net.ssl.X509TrustManager

object TestCase {
	class Violation1: X509TrustManager {
		@Throws(CertificateException::class)
		override fun checkClientTrusted(chain: Array<out X509Certificate>?, authType: String?) {
			// Do nothing
		}

		@Throws(CertificateException::class)
		override fun checkServerTrusted(chain: Array<out X509Certificate>?, authType: String?) {				// @violation
			// Do nothing
		}

		override fun getAcceptedIssuers(): Array<X509Certificate> {
			return mutableListOf<X509Certificate>().toTypedArray()
		}
	}

	class Violation2: X509TrustManager {
		private val LOG = Logger.getGlobal()

		@Throws(CertificateException::class)
		override fun checkClientTrusted(chain: Array<out X509Certificate>?, authType: String?) {
			// Do nothing
		}

		@Throws(CertificateException::class)
		override fun checkServerTrusted(chain: Array<out X509Certificate>?, authType: String?) {				// @violation
			LOG.severe("ERROR_MESSAGE")
		}

		override fun getAcceptedIssuers(): Array<X509Certificate> {
			return mutableListOf<X509Certificate>().toTypedArray()
		}
	}

	class good: X509TrustManager {
		private val LOG = Logger.getGlobal()

		@Throws(CertificateException::class)
		override fun checkClientTrusted(chain: Array<out X509Certificate>?, authType: String?) {
			// Do nothing
		}

		@Throws(CertificateException::class)
		override fun checkServerTrusted(chain: Array<out X509Certificate>?, authType: String?) {
			if (certificates.length == 1) {
				// if certificates have only one, check the validity simply
				certificates[0].checkValidity()
			}
			else if (standardTrustManager != null) {
				standardTrustManager.checkServerTrusted(certificates, authType)
			}
			else {
				LOG.severe("ERROR_MESSAGE")
				throw CertificateException("there were one more certificates but no trust manager found.")		// good
			}
		}

		override fun getAcceptedIssuers(): Array<X509Certificate> {
			return mutableListOf<X509Certificate>().toTypedArray()
		}
	}
}