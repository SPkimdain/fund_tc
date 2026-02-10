
/* DUTV_032 - Support setting function parameter as sink point, scaffold sink case1 */

struct DUTV_032_WebPacket {
  int len;
  char data[20];
};

/* Only size is tainted. */
extern void hw_memcpy(char* dst, char* src, int size);

DUTV_032_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

void DUTV_032_function2(DUTV_032_WebPacket* packet, char* src) {
  /* do something */
  char dst[10];

  hw_memcpy(dst, src, packet->len); /* violation. */

}


void DUTV_032_function3(char* pMsg, char* src, int len) {
  DUTV_032_WebPacket* packet = getpacket(pMsg);

  DUTV_032_function2(packet, src);  //@violation DANGEROUS_USE_OF_TAINTED_VALUES
}
