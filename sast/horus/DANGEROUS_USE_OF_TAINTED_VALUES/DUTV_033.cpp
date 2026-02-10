
/* DUTV_033 - function sink - scaffold sink case2 */

struct DUTV_033_WebPacket {
  int len;
  char data[20];
};

extern void hw_memcpy(char* dst, char* src, int size);

DUTV_033_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

void DUTV_033_function(char* pMsg, int len, char* src) {
  DUTV_033_WebPacket* packet = getpacket(pMsg);
  /* do something */
  char dst[10];

  hw_memcpy(dst, packet->data, len); //It's ok.

  hw_memcpy(dst, src, packet->len);  //@violation DANGEROUS_USE_OF_TAINTED_VALUES

}
