
/* DUTV_035 - function sink complex2 */

struct DUTV_035_WebPacket {
  int len;
  char data[20];
};

extern void hw_memcpy(char* dst, char* src, int size);

DUTV_035_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

void DUTV_035_function(char* pMsg, char* src) {
  DUTV_035_WebPacket* packet = getpacket(pMsg);
  /* do something */
  char dst[10];

  hw_memcpy(packet->data, src, 3); //It's ok. packet->data is tainted but it just object.

  /* The offset of packet->data is tainted(packet->len). It is a problem. (sink: hw_memcpy, 1st param) */
  hw_memcpy(packet->data + packet->len, src, 3);  //@violation DANGEROUS_USE_OF_TAINTED_VALUES

}
