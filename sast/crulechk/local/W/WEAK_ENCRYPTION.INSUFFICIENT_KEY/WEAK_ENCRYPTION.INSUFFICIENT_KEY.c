// @checker WEAK_ENCRYPTION.INSUFFICIENT_KEY

#define NULL 0
extern int printf ( const char * format, ... );

typedef struct _RSA {
	int dummy;
} RSA;

extern RSA * RSA_generate_key(int, int, void *, void *);

void badKey1() {
	RSA * rsa;
	rsa = RSA_generate_key(512, 35, NULL, NULL); // @violation WEAK_ENCRYPTION.INSUFFICIENT_KEY
	if(rsa == NULL) {
		printf("Error\n");
	}
}

void badKey2() {
	RSA * rsa;
	int keyLength = 512;
	rsa = RSA_generate_key(keyLength, 35, NULL, NULL); // @violation WEAK_ENCRYPTION.INSUFFICIENT_KEY
	if(rsa == NULL) {
		printf("Error\n");
	}
}

void badKey3(int longKey) {
	RSA * rsa;
	int keyLength;
	if(longKey) {
		keyLength = 1024;
	} else {
		keyLength = 512;
	}
	rsa = RSA_generate_key(keyLength, 35, NULL, NULL); // @violation WEAK_ENCRYPTION.INSUFFICIENT_KEY
	if(rsa == NULL) {
		printf("Error\n");
	}
}

void goodKey() {
	RSA * rsa;
	rsa = RSA_generate_key(1024, 35, NULL, NULL);
	if(rsa == NULL) {
		printf("Error\n");
	}
}

