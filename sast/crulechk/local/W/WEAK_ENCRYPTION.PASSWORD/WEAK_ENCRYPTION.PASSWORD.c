// @checker WEAK_ENCRYPTION.PASSWORD
// Dummy defines
#define RSA_PKCS1_PADDING 0

// Dummy types
typedef int SQLHENV;
typedef int SQLHDBC;
typedef char SQLCHAR;
typedef int RSA;
typedef long size_t;

extern size_t strlen ( const char * str );
// Dummy function
void SQLConnect(SQLHDBC hdbc, SQLCHAR * server, int serverlen, char * user, int userlen, char * pw, int pwlen);
char * base64_decode(char * pw);
void RSA_private_decrypt(int cpwlen, char * cpw, char * pw, RSA * rsa, int opt);

int dbaccess(char * server, char * user, char * cpw, RSA * rsa) {
	SQLHENV henv;
	SQLHDBC hdbc;
	char * pw;
	
	// Do something

    pw = base64_decode(cpw);	
	SQLConnect(hdbc, (SQLCHAR *)server, strlen(server), user, strlen(user), pw, strlen(pw)); // @violation WEAK_ENCRYPTION.PASSWORD
	
	RSA_private_decrypt(strlen(cpw), cpw, pw, rsa, RSA_PKCS1_PADDING);
	SQLConnect(hdbc, (SQLCHAR *)server, strlen(server), user, strlen(user), pw, strlen(pw));
	return 0;
}
