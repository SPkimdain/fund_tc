import android.app.Activity;

import java.security.cert.Certificate;
import java.security.cert.X509Certificate;

import javax.net.ssl.HostnameVerifier;
import javax.net.ssl.HttpsURLConnection;
import javax.net.ssl.SSLException;
import javax.net.ssl.SSLSession;

public class AndroidUnsafeHostnameVerification extends Activity {
    public void violation() {
        HostnameVerifier verifier = new HostnameVerifier() {
            @Override
            public boolean verify(String hostname, SSLSession session) {
                return true;                                                // @violation
            }
        };
        HttpsURLConnection.setDefaultHostnameVerifier(verifier);
    }

    public void good() {
        HostnameVerifier verifier = new HostnameVerifier() {
            @Override
            public boolean verify(String hostname, SSLSession session) {
                try {
                    Certificate[] certs = session.getPeerCertificates();
                    X509Certificate x509 = (X509Certificate) certs[0];
                    check(new String[]{host}, x509);
                    return true;                                            /* SAFE */
                } catch (SSLException e) {
                    return false;
                }
            }
        };
        HttpsURLConnection.setDefaultHostnameVerifier(verifier);
    }
}