//@checker WEAK_SERVER_CERTIFICATES.CPP 

#define CURLOPT_SSL_VERIFYPEER 64
#define CURLOPT_URL 10002

class CURL {}; //dummy

extern CURL* curl_easy_init();
extern void curl_easy_setopt(CURL* url, int option, const char* urlStr);
extern void curl_easy_setopt(CURL* url, int option, int value);
extern void curl_easy_perform(CURL* url);

class SSL_METHOD {};
class SSL_CTX {};
class X509_STORE_CTX {};
class SSL {};

extern SSL_METHOD* TLS_method();
extern SSL_CTX* SSL_CTX_new(SSL_METHOD* method);
extern void SSL_CTX_set_verify(SSL_CTX* ctx, int mode,
  int(*verify_callback)(int, X509_STORE_CTX *));
extern SSL* SSL_new(SSL_CTX* ctx);
extern void SSL_connect(SSL* ssl);

#define SSL_VERIFY_NONE 0x00


void WSERVCERT_001_function() {
  CURL *curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");

    /* Set the default value: strict certificate check please */
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0); //@violation WEAK_SERVER_CERTIFICATES.CPP

    curl_easy_perform(curl);
  }

}

void WSERVCERT_001_function2() {
  const SSL_METHOD* method = TLS_method();
  if(method != 0) {
    SSL_CTX* ctx = SSL_CTX_new(method);
    if(ctx != 0) {
      SSL_CTX_set_verify(ctx, SSL_VERIFY_NONE, 0); //@violation WEAK_SERVER_CERTIFICATES.CPP
    }
  }
}
