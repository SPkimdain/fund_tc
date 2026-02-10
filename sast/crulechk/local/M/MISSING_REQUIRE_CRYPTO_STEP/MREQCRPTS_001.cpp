//@checker MISSING_REQUIRE_CRYPTO_STEP
#define MS_ENH_RSA_AES_PROV "dummy"
#define PROV_RSA_AES 0

typedef void* HCRYPTPROV;
typedef void* HCRYPTHASH;
typedef char BYTE;
typedef long size_t;

extern size_t strlen ( const char * str );
extern int CryptAcquireContext(HCRYPTPROV* prov, char* cont, const char* provider, int type, int flag);
extern int CryptHashData(HCRYPTHASH hHash, BYTE* data, int len, int flag);

int MREQCRPTS_001_function(HCRYPTPROV hCryptProv, HCRYPTHASH hHash, char* hashData) {  
  if(!CryptAcquireContext(&hCryptProv, 0, MS_ENH_RSA_AES_PROV, PROV_RSA_AES, 0)) {
    return 1;
  }


  if(!CryptHashData(hHash, (BYTE*)hashData, strlen(hashData), 0)) { //@violation MISSING_REQUIRE_CRYPTO_STEP
    return 0;
  }
  
  
  return -1;
}
