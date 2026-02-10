import android.webkit.WebView;

public class AndroidAddJavascriptInterface extends Activity {
    @Override
    public void onCreate_1(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        WebView webView = new WebView(this);
        setContentView(webView);
        class JsObject {
            private String sensitiveInformation;

            public String toString() { return sensitiveInformation; }

        }

        webView.addJavascriptInterface(new JsObject(), "injectedObject");   // @violation
        webView.loadData("", "text/html", null);
        webView.loadUrl("http://www.example.com");
    }

    @Override
    public void onCreate_2(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        WebView webView = new WebView(this);
        setContentView(webView);
        class JsObject {
            private String sensitiveInformation;

            public String toString() { return sensitiveInformation; }

        }

        webView.getSettings().setJavaScriptEnabled(true);                   // @violation
        webView.loadData("", "text/html", null);
        webView.loadUrl("http://www.example.com");
    }

    @Override
    public void onCreate_Safe(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        WebView webView = new WebView(this);
        setContentView(webView);

        // Safe, Unless webView.addJavascriptInterface(new JsObject(), "injectedObject"); calls
    }
}
