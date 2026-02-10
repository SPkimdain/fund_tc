
/* DUTV_005 - function sink pointer assign */

struct DUTV_005_WebPacket {
  int len;
  char data[20];
};

extern void hw_memcpy(char* dst, char* src, int size);

DUTV_005_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

void DUTV_005_function(char* pMsg, int flag, int len) {
  DUTV_005_WebPacket* packet = getpacket(pMsg);
  /* do something */
  char dst[10];

  char* ptr = packet->data;

  if(flag > 10) {
    hw_memcpy(dst, ptr, len); //It's ok.
    
    hw_memcpy(dst, ptr, packet->len); //@violation DANGEROUS_USE_OF_TAINTED_VALUES
  }
}
