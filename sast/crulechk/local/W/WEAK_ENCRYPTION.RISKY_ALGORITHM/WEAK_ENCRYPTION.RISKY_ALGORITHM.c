// @checker WEAK_ENCRYPTION.RISKY_ALGORITHM

typedef struct _EVP_CIPHER_CTX {
	int dummy;
} EVP_CIPHER_CTX;

extern void EVP_CIPHER_CTX_init(EVP_CIPHER_CTX *);
extern void EVP_EncryptInit(EVP_CIPHER_CTX *, void *, unsigned char *, unsigned char *);
extern void * EVP_des_ecb();
extern void * EVP_aes_128_cbc();

void badAlgorithm(unsigned char * key, unsigned char * iv) {
	EVP_CIPHER_CTX ctx;
	EVP_CIPHER_CTX_init(&ctx);
	
	// Do something
	
	EVP_EncryptInit(&ctx, EVP_des_ecb(), key, iv); // @violation WEAK_ENCRYPTION.RISKY_ALGORITHM
}

void goodAlgorithm(unsigned char * key, unsigned char * iv) {
	EVP_CIPHER_CTX ctx;
	EVP_CIPHER_CTX_init(&ctx);
	
	// Do something
	
	EVP_EncryptInit(&ctx, EVP_aes_128_cbc(), key, iv);
}

