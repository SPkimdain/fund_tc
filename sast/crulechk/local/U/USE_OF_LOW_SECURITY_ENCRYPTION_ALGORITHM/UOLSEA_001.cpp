//@checker USE_OF_LOW_SECURITY_ENCRYPTION_ALGORITHM

#define EscRsa_KEY_BYTES (128U) //@violation USE_OF_LOW_SECURITY_ENCRYPTION_ALGORITHM

typedef unsigned char uint8;

struct Des3Cbc_ContextT {};
typedef enum {
  EX_RT_OK = 0,
  EX_RT_NOT_OK = 1,
} Ex_ReturnType;


Ex_ReturnType Des3Cbc_Init(Des3Cbc_ContextT* ctx, uint8*, uint8*, uint8*, void*);
Ex_ReturnType Des3Cbc_Encrypt(Des3Cbc_ContextT* ctx, uint8* msg, uint8* cipher, int size);

int UOLSEA_001_function(uint8* key1, uint8* key2, uint8* iv, uint8* plainMsg, uint8* cipherMsg) {
  Des3Cbc_ContextT des3Ctx1;
  Ex_ReturnType result = Des3Cbc_Init(&des3Ctx1, key1, key1, key2, iv); //@violation USE_OF_LOW_SECURITY_ENCRYPTION_ALGORITHM
  if(result == EX_RT_OK) {
    result = Des3Cbc_Encrypt(&des3Ctx1, plainMsg, cipherMsg, 512);
    if(result == EX_RT_OK) {
      /* The code is omitted. */
      return 1;
    }
  }

  return -1;
}
