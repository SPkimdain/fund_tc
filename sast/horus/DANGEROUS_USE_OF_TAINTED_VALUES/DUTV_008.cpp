
/* DUTV_008 - sanitize check */

struct DUTV_008_WebPacket {
  int len;
  char data[20];
};

extern void hw_memcpy(char* dst, char* src, int size);
extern DUTV_008_WebPacket* sanitizeDummy(DUTV_008_WebPacket* obj);

DUTV_008_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

void DUTV_008_function(char* pMsg) {
  DUTV_008_WebPacket* packet = getpacket(pMsg);
  /* do something */
  char dst[10];

  packet = sanitizeDummy(packet);

  hw_memcpy(dst, packet->data, packet->len); //It's ok.

}

void DUTV_008_function2(char* pMsg) {
  DUTV_008_WebPacket* packet = getpacket(pMsg);
  /* do something */
  char dst[10];

  hw_memcpy(dst, packet->data, packet->len);  //@violation DANGEROUS_USE_OF_TAINTED_VALUES

}
