
/* DUTV_006 - function sink pointer assign, complex */

struct DUTV_006_WebPacket {
  int len;
  char data[20];
};

extern void hw_memcpy(char* dst, char* src, int size);

DUTV_006_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

char* DUTV_006_getPtr(char* ptr, char* ptr2, int flag) {
  if(flag == 10) {
    return ptr;
  }
  else {
    return ptr2;
  }
}

void DUTV_006_function2(char* pMsg, int flag, int len, char* securePtr) {
  DUTV_006_WebPacket* packet = getpacket(pMsg);
  /* do something */
  char dst[10];

  char* ptr = packet->data;
  

  if(flag > 10) {
    char* check = DUTV_006_getPtr(ptr, securePtr, 20);

    hw_memcpy(dst, check, len); //It's ok.
  } 
  else {
    char* check2 = DUTV_006_getPtr(ptr, securePtr, 10);

    hw_memcpy(dst, check2, len); //It's ok.
    
    hw_memcpy(dst, check2, packet->len); //@violation DANGEROUS_USE_OF_TAINTED_VALUES
  }
}
