public class AndoridWebSettingJavaScript extends Activity {
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        WebView webView = (WebView) findViewById(R.id.webview);


        // turn on javascript
        WebSettings settings = webView.getSettings();
        settings.setJavaScriptEnabled(true);            // @violation

        String turl = getIntent().getStringExtra("URL");
        webView.loadUrl(turl);
    }

    @Override
    public void onCreateSafe(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        WebView webView = (WebView) findViewById(R.id.webview);


        // turn on javascript
        WebSettings settings = webView.getSettings();
        settings.setJavaScriptEnabled(false);            // Safe

        String turl = getIntent().getStringExtra("URL");
        webView.loadUrl(turl);
    }
}