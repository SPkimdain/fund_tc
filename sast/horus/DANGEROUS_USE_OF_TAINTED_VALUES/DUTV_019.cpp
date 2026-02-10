
/* DUTV_019 - Support loop bound taint check case1 */


struct DUTV_019_WebPacket {
  int len;
  char data[20];
};

extern void hw_memcpy(char* dst, char* src, int size);

DUTV_019_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.



void DUTV_019_function2(char* pMsg, int* arr) {
  DUTV_019_WebPacket* packet = getpacket(pMsg);

  for(int i = 0; i < packet->len; i++) { //@violation DANGEROUS_USE_OF_TAINTED_VALUES
    arr[i] = i + 10;
  }
}


