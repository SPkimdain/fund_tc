#include <stdio.h>
#include <memory.h>

/* DUTV_036 - function sink complex3 */

struct DUTV_036_WebPacket {
  int len;
  char data[20];
};

DUTV_036_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

void DUTV_036_function(char* pMsg, char* src) {
  DUTV_036_WebPacket* packet = getpacket(pMsg);
  /* do something */
  char dst[10];

  memcpy(packet->data, src, 3); //It's ok. packet->data is tainted but it just object.

  /* The offset of packet->data is tainted(packet->len). It is a problem. (sink: memcpy, 1st param) */
  memcpy(packet->data + packet->len, src, 3);  //@violation DANGEROUS_USE_OF_TAINTED_VALUES
}
