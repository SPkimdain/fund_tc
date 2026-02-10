package testcase.rule.security.ServerSideRequestForgeryChecker

import java.net.HttpURLConnection
import java.net.URI
import java.net.URL
import java.net.http.HttpRequest
import javax.servlet.http.HttpServletRequest
import okhttp3.Request
import org.apache.http.client.methods.HttpGet
import org.jsoup.Jsoup

object TestCase {
	fun violation(request: HttpServletRequest) {
		val urlText = request.getParameter("url")
		val url = URL(urlText)
		val connection = url.openConnection() as HttpURLConnection		// @violation
	}

    fun violation2(request: HttpServletRequest) {
        val urlText = request.getParameter("url")
        val client = HttpClients.createDefault()
        val res = HttpGet(urlText)      // @violation
        client.execute(res)
    }

    fun violation3(request: HttpServletRequest) {
        val urlText = request.getParameter("url")
        val rb = Request().newBuilder().url(urlText).build()  // @violation
        client.execute(res)
    }

    fun violation4(request: HttpServletRequest) {
        val urlText = request.getParameter("url")
        HttpRequest.newBuilder().uri(URI.create(urlText)).build()  // @violation
        client.execute(res)
    }

    fun violation5(request: HttpServletRequest) {
        val urlText = request.getParameter("url")
        Jsoup.connect(urlText).get()            // @violation
        Jsoup.connect(urlText).post()           // @violation
        Jsoup.connect(urlText).execute()        // @violation
        client.execute(res)
    }

	fun good1(request: HttpServletRequest) {
		val urlWhiteListed = "https://example.com/"
		val urlText = request.getParameter("url")
		if (urlText.startsWith(urlWhiteListed)) {
			val url = URL(urlText)
			val connection = url.openConnection() as HttpURLConnection	// good
		}
	}

	val urlMap: Map<String, URL> = java.util.Collections.emptyMap();

	fun good2(request: HttpServletRequest) {
		val url1 = urlMap.get(request.getParameter("url"))
		val connection1 = url1?.openConnection() as HttpURLConnection	// good

		val url2 = urlMap[request.getParameter("url")]
		val connection2 = url2?.openConnection() as HttpURLConnection	// good
	}
}