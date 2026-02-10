package testcase.rule.security.WeakCertTrustChainChecker

import io.netty.handler.ssl.SslContextBuilder
import io.netty.handler.ssl.util.InsecureTrustManagerFactory
import org.apache.hc.client5.http.ssl.TrustAllStrategy
import org.apache.hc.core5.ssl.SSLContextBuilder
import javax.net.ssl.X509TrustManager

class TestImplClass: X509TrustManager {
    override fun checkClientTrusted(c: Array<X509Certificate>, a: String) {     // @violation

    }
    override fun checkServerTrusted(c: Array<X509Certificate>, a: String) {}    // @violation

    override fun getAcceptedIssuers(): Array<X509Certificate> = emptyArray()
}

object TestCase {
    val tm = object : X509TrustManager {
        override fun checkClientTrusted(c: Array<X509Certificate>, a: String) {     // @violation

        }
        override fun checkServerTrusted(c: Array<X509Certificate>, a: String) {}    // @violation

        override fun getAcceptedIssuers(): Array<X509Certificate> = emptyArray()
    }

    object TestImplObject: X509TrustManager {
        override fun checkClientTrusted(c: Array<X509Certificate>, a: String) {     // @violation

        }
        override fun checkServerTrusted(c: Array<X509Certificate>, a: String) {}    // @violation

        override fun getAcceptedIssuers(): Array<X509Certificate> = emptyArray()
    }

    fun violationApache() {
        val ctx = SSLContextBuilder.create()
            .loadTrustMaterial(TrustAllStrategy.INSTANCE)  // @violation
            .build()
    }

    fun violationNetty() {
        val nettySsl = SslContextBuilder.forClient()
            .trustManager(InsecureTrustManagerFactory.INSTANCE) // @violation
            .build()
    }
}