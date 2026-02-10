//@checker USE_RSA_WITHOUT_OAEP

typedef void* HCRYPTKEY;
typedef void* HCRYPTHASH;

extern int CryptEncrypt(HCRYPTKEY hKey, HCRYPTHASH hash, char final, short flag, char* data, short* len, short bufLen);
extern int printf ( const char * format, ... );

int URSAWO_001_function(HCRYPTKEY hKey, short payloadLen, short bufLen) {
  char payload[256] = { 0, };
  int x = 0;
  
  if(!CryptEncrypt(hKey, (HCRYPTHASH)0, 1, 0, (char *)payload, &payloadLen, sizeof(payload))) //@violation USE_RSA_WITHOUT_OAEP
  {
      printf("Error in CryptEncryptData");
      return 0;
  }
  
  return 1;
}

