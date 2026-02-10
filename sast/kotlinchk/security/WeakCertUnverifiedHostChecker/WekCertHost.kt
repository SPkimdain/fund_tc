package testcase.rule.security.WeakCertUnverifiedHostChecker

import io.netty.handler.ssl.SslContextBuilder
import io.netty.handler.ssl.SslHandler
import jakarta.ws.rs.client.ClientBuilder
import java.net.URL
import javax.net.ssl.HostnameVerifier
import javax.net.ssl.HttpsURLConnection
import javax.net.ssl.SSLParameters
import javax.net.ssl.SSLSession
import javax.net.ssl.SSLSocket
import javax.net.ssl.SSLSocketFactory
import okhttp3.OkHttpClient
import org.apache.hc.client5.http.ssl.NoopHostnameVerifier
import org.apache.hc.client5.http.ssl.SSLConnectionSocketFactoryBuilder
import reactor.netty.http.client.HttpClient

object TestCase {
    fun violation(input: String) {
        val conn1 = (URL(input).openConnection() as HttpsURLConnection).apply {
            hostnameVerifier = HostnameVerifier { _, _ -> true }                        // @violation
        }

        val conn2 = (URL(input).openConnection() as HttpsURLConnection).apply {
            HttpsURLConnection.setDefaultHostnameVerifier { _, _ -> true }              // @violation
        }

        val client1 = OkHttpClient.Builder()
            .hostnameVerifier { _: String?, _: SSLSession? -> true }                    // @violation
            .build()

        val client2 = ClientBuilder.newBuilder()
            .hostnameVerifier(HostnameVerifier { _: String?, _: SSLSession? -> true })  // @violation
            .build()

        val sf = SSLConnectionSocketFactoryBuilder.create()
            .setHostnameVerifier(NoopHostnameVerifier.INSTANCE)                         // @violation
            .build()
    }

    fun violation2(host: String) {
        val params1 = SSLParameters().apply {
            endpointIdentificationAlgorithm = null              // @violation
        }

        val params2 = SSLParameters().apply {
            endpointIdentificationAlgorithm = ""                // @violation
        }

        val sock = (SSLSocketFactory.getDefault().createSocket(host, 443) as SSLSocket).apply {
            sslParameters = sslParameters.apply {
                endpointIdentificationAlgorithm = null          // @violation
            }
        }
    }
}