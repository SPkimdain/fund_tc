
/* DUTV_001 - Support setting function parameter as sink point, simple case1 */

struct DUTV_001_WebPacket {
  int len;
  char data[20];
};

extern void hw_memcpy(char* dst, char* src, int size);

DUTV_001_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

void DUTV_001_function(DUTV_001_WebPacket* packet) {
  /* do something */
  char dst[10];
    
  hw_memcpy(dst, packet->data, packet->len); /* passing taint variable to taint sink */  

}


void DUTV_001_function2(char* pMsg) {
  DUTV_001_WebPacket* packet = getpacket(pMsg);

  
  DUTV_001_function(packet);  //@violation DANGEROUS_USE_OF_TAINTED_VALUES
}
