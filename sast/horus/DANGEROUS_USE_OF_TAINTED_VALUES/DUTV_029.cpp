
/* DUTV_029 - sanitize / compare case1 */

struct DUTV_029_WebPacket {
  int len;
  char data[20];
};

extern void hw_memcpy(char* dst, char* src, int size);

DUTV_029_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

void DUTV_029_function(int len, char* src) {
  /* do something */
  char dst[10];

  hw_memcpy(dst, src, len); /* passing taint variable to taint sink */

}

void DUTV_029_function2(char* pMsg, char* src) {
  DUTV_029_WebPacket* packet = getpacket(pMsg);
  if(packet == 0) {
    return;
  }

  if(packet->len > 9) { //sanitize.
    return;
  }

  DUTV_029_function(packet->len, src); //It's ok.
}

void DUTV_029_function3(char* pMsg, int len) {
  DUTV_029_WebPacket* packet = getpacket(pMsg);
  if(packet == 0) { 
    return;
  }

  DUTV_029_function(packet->len, packet->data);  //@violation DANGEROUS_USE_OF_TAINTED_VALUES
}
