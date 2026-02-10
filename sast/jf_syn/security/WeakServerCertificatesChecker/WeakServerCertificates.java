//WEAK_SERVER_CERTIFICATES
package security;

import javax.net.ssl.X509TrustManager;
import java.security.cert;

public  class WeakServerCertificates implements X509TrustManager {

    @Override
    public void checkClientTrusted(X509Certificate[] chain, String authType) throws CertificateException {  // @violation
    }

    @Override
    public void checkServerTrusted(X509Certificate[] chain, String authType) throws CertificateException {  // @violation
        try {
            LOG.log(Level.SEVERE, ERROR_MESSAGE);
        } catch (Exception e) {
            throw e;
        }
    }

    @Override
    public X509Certificate[] getAcceptedIssuers() {
        return null;
    }
}