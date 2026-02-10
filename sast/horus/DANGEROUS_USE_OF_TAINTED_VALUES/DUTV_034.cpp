
/* DUTV_034 - function sink complex1 */

struct DUTV_034_WebPacket {
  int len;
  char data[20];
};

extern void hw_memcpy(char* dst, char* src, int size);

DUTV_034_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

void DUTV_034_function(char* pMsg, char* src) {
  DUTV_034_WebPacket* packet = getpacket(pMsg);
  /* do something */
  char dst[10];

  /* The offset of packet->data is tainted(packet->len). It is a problem. (sink: hw_memcpy, 2nd param) */
  hw_memcpy(dst, packet->data + packet->len, 3);  //@violation DANGEROUS_USE_OF_TAINTED_VALUES

}
