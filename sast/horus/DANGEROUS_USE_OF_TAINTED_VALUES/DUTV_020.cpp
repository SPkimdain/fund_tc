
/* DUTV_020 - Support loop bound taint check case2 */


struct DUTV_020_WebPacket {
  int len;
  char data[20];
};

extern void hw_memcpy(char* dst, char* src, int size);

DUTV_020_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

void DUTV_020_function(DUTV_020_WebPacket* packet) {
  /* do something */
  int a[10] = { 0, };

  for(int i = 0; i < packet->len; i++) {
    a[i] = i + 10;
  }
}


void DUTV_020_function2(char* pMsg) {
  DUTV_020_WebPacket* packet = getpacket(pMsg);


  DUTV_020_function(packet);  //@violation DANGEROUS_USE_OF_TAINTED_VALUES
}


