//@checker WEAK_ENCRYPTION.RSA_PADDING

#define RSA_NO_PADDING 3

struct RSA { };   //dummy.

extern RSA* RSA_new();
void RSA_public_encrypt(int size, char* text, char* out, RSA* rsa, int padding);

void WENCRSAPD_001_function(char *text, int size){
  char out[512];
  RSA *rsa_p = RSA_new();
  RSA_public_encrypt(size, text, out, rsa_p, RSA_NO_PADDING); //@violation WEAK_ENCRYPTION.RSA_PADDING
}
