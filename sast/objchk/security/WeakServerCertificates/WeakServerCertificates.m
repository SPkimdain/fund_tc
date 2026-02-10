#include <openssl/ssl.h>

void testFunction() {
  const SSL_METHOD* method = TLS_method();
  SSL_CTX* ctx = SSL_CTX_new(method);

  SSL_CTX_set_verify(ctx, SSL_VERIFY_NONE, NULL); //@violation

  SSL *ssl = SSL_new(ctx);
}

void testFunction2() {
  const SSL_METHOD* method = TLS_method();
  SSL_CTX* ctx = SSL_CTX_new(method);

  SSL_CTX_set_verify(ctx, CURLOPT_SSL_VERIFYPEER, NULL); //@violation

  SSL *ssl = SSL_new(ctx);
}

