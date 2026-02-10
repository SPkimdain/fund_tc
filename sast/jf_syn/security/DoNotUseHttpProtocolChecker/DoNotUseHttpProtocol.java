
public class UsingHttpProtocal {

    URL badUrl1 = new URL("http://www.sparrowfasoo.com");       // @violation
    URL goodUrl1 = new URL("https://www.sparrowfasoo.com");     // good

    String badUrl2 = "http";                                    // @violation
    String badUrl3 = "httphttphttp";                            // @violation
    String badUrl4 = "HTTP";                                    // @violation
    String goodUrl2 = "https";                                  // good
    String goodUrl3 = "https://www.sparrow.com/blahhttpblahblah.html"; // good
    String goodUrl4 = "HTTPS";                                  // good

    public void badHttp1() {
        URL url = new URL("http://www.sparrowfasoo.com");       // @violation
    }

    public void goodHttp1() {
        URL url = new URL("https://www.sparrowfasoo.com");       // good
    }

    public void connectHttp(Url url) {
        HttpURLConnection http = (HttpURLConnection) url.openConnection();
    }

    public badHttp2() {
        String a = "http://www.sparrowfasoo.com";               // @violation
        connectHttp(new URL(a));
    }

    public goodHttp2() {
        String a = "https://www.sparrowfasoo.com";              // good
        connectHttp(new URL(a));
    }

    public badHttp3() {
        String a = "http://www.sparrowfasoo.com";               // @violation
    }

    public goodHttp3() {
        String a = "https://www.sparrowfasoo.com";              // good
    }

    public badHttp4() {
        String a = "http";                                      // @violation
    }

    public goodHttp4() {
        String a = "https";                                     // good
    }

    public badHttp5() {
        Url url = new URL("http", "www.sparrowfasoo.com");      // @violation
    }

    public goodHttp5() {
        Url url = new URL("https", "www.sparrowfasoo.com");     // good
    }
}