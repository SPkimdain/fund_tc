package ti;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.webkit.WebView;
import android.webkit.WebViewClient;

public class ANDROID_XSS_Testcase extends Activity {

    private void violation1() {
        Intent intent = getIntent();
        if(intent != null) {
            String url = intent.getStringExtra("url");

            WebView webView = (WebView) findViewById(1);
            webView.setWebViewClient(new WebViewClient());
            if(url != null) {
                webView.loadUrl(url);               /* BUG */
            }
        }
    }

    private void violation2() {
        Intent intent = getIntent();
        if(intent != null) {
            Bundle bundle = intent.getExtras();
            if(bundle != null) {
                String url = bundle.getString("url");

                WebView webView = (WebView) findViewById(1);
                webView.setWebViewClient(new WebViewClient());
                if(url != null) {
                    webView.loadUrl(url);           /* BUG */
                }
            }
        }
    }

    private void good1() {
        Intent intent = getIntent();
        if(intent != null) {
            String url = intent.getStringExtra("url");

            WebView webView = (WebView) findViewById(1);
            webView.setWebViewClient(new WebViewClient());
            if(url != null && url.startsWith("http://example.com/")) {
                webView.loadUrl(url);               /* GOOD */
            }
        }
    }

    private void good2() {
        Intent intent = getIntent();
        if(intent != null) {
            Bundle bundle = intent.getExtras();
            if(bundle != null) {
                String url = bundle.getString("url");

                WebView webView = (WebView) findViewById(1);
                webView.setWebViewClient(new WebViewClient());
                if(url != null && url.startsWith("http://example.com/")) {
                    webView.loadUrl(url);           /* GOOD */
                }
            }
        }
    }
}