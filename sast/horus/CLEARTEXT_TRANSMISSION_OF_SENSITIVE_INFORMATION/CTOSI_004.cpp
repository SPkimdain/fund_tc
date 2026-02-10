
/* CTOSI_004 - simple case2 */

#define AES_BLOCK_BYTES 4
#define AES_KEY_BYTES 4

typedef enum {
  EX_RT_OK = 0,
  EX_RT_NOT_OK = 1,
} Ex_ReturnType;

extern unsigned char vehicleKey[16];
extern unsigned char velocityData1;
extern unsigned char velocityData2;
extern unsigned char velocityData3;
extern unsigned char velocityData4;

extern unsigned char publishCANData(unsigned char * payload);


struct AesOmac1_ContextT {};

extern Ex_ReturnType AesOmac1_Init(AesOmac1_ContextT* ctx, unsigned char* key);
extern Ex_ReturnType AesOmac1_Update(AesOmac1_ContextT* ctx, unsigned char* msg, int size);
extern Ex_ReturnType AesOmac1_Finish(AesOmac1_ContextT* ctx, unsigned char* cmac, int size);

int CTOSI_004_function1(int flag) {
  AesOmac1_ContextT ctx;

  unsigned char cmac[AES_BLOCK_BYTES] = { 0, };
  unsigned char msg[4] = { 0, };
  unsigned char sendData[4 + AES_BLOCK_BYTES] = { 0, };

  msg[0] = velocityData1;
  msg[1] = velocityData2;
  msg[2] = velocityData3;
  msg[3] = velocityData4;
  
  Ex_ReturnType result = AesOmac1_Init(&ctx, vehicleKey);
  if(result == EX_RT_OK) {
    result = AesOmac1_Update(&ctx, msg, 4);
    if(result == EX_RT_OK) {
      result = AesOmac1_Finish(&ctx, cmac, AES_KEY_BYTES);
      if(result == EX_RT_OK) {
        for(int i = 0; i < AES_BLOCK_BYTES; i++) {
          sendData[i] = cmac[i];
        }
        sendData[4] = velocityData1;
        sendData[5] = velocityData2;
        sendData[6] = velocityData3;
        sendData[7] = velocityData4;

        publishCANData(sendData); //It's ok.
      }
    }
  }
  else {
    unsigned char* forward = msg;
    if(flag > 10) {
      publishCANData(forward); //@violation CLEARTEXT_TRANSMISSION_OF_SENSITIVE_INFORMATION
    }
  }

  return 0;
}
