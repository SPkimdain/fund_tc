
/* DUTV_003 - Support setting function parameter as sink point, simple case3 */

struct DUTV_003_WebPacket {
  int len;
  char data[20];
};

extern void hw_memcpy(char* dst, char* src, int size);

DUTV_003_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

void DUTV_003_function(int len, char* src) {
  /* do something */
  char dst[10];

  hw_memcpy(dst, src, len); /* passing taint variable to taint sink */

}


void DUTV_003_function2(char* pMsg, int len, char* src) {
  DUTV_003_WebPacket* packet = getpacket(pMsg);
  if(packet == 0) {
    return;
  }

  char* offset = src + 1;
  
  DUTV_003_function(packet->len, offset); //@violation DANGEROUS_USE_OF_TAINTED_VALUES
}
