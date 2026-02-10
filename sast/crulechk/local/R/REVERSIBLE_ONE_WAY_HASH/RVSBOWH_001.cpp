//@checker REVERSIBLE_ONE_WAY_HASH
#define CALG_MD2 0x00008001
#define CALG_MD5 0x00008003
#define CALG_SHA1 0x00008004

typedef void* HCRYPTPROV;
typedef int ALG_ID;
typedef void* HCRYPTHASH;
typedef char HCRYPTKEY;
typedef short DWORD;


extern int CryptCreateHash(HCRYPTPROV hProv,
  ALG_ID     Algid,
  HCRYPTKEY  hKey,
  DWORD      dwFlags,
  HCRYPTHASH *phHash
);

extern int CryptReleaseContext(HCRYPTPROV hProv, int flag);

int RVSBOWH_001_function(HCRYPTPROV hCryptProv, HCRYPTHASH hHash) {
  if (!CryptCreateHash(hCryptProv, CALG_MD2, 0, 0, &hHash)) //@violation REVERSIBLE_ONE_WAY_HASH
  {
      CryptReleaseContext(hCryptProv, 0);
      return 1;
  }
  
  return 0;
}

