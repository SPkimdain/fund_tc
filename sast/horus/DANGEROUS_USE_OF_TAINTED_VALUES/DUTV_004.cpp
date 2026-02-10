
/* DUTV_004 - function sink simple case1 */

struct DUTV_004_WebPacket {
  int len;
  char data[20];
};

extern void hw_memcpy(char* dst, char* src, int size);

DUTV_004_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

void DUTV_004_function(char* pMsg) {
  DUTV_004_WebPacket* packet = getpacket(pMsg);
  /* do something */
  char dst[10];

  hw_memcpy(dst, packet->data, packet->len);  //@violation DANGEROUS_USE_OF_TAINTED_VALUES

}
