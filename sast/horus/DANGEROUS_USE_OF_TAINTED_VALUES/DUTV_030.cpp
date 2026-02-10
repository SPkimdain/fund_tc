
/* DUTV_030 - sanitize / compare case2 */

struct DUTV_030_WebPacket {
  int len;
  char data[20];
};

extern void hw_memcpy(char* dst, char* src, int size);

DUTV_030_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

void DUTV_030_function(char* pMsg, int len, int* arr) {
  int ret = 0;
  int index = 0;

  DUTV_030_WebPacket* packet = getpacket(pMsg); //it is tainted.

  for(int i = 0; i < len; i++) {
    ret += arr[i]; //it's ok.

    //it will cause OOB read for the next loop.
    ret += arr[index]; //it's ok.

    if(packet->len > 100 || packet->len < 0) { //sanitize.
      break;
    }

    index += packet->len;
    /* index is tainted. */
  }
}


void DUTV_030_function2(char* pMsg, int len, int* arr) {
  int ret = 0;
  int index = 0;

  DUTV_030_WebPacket* packet = getpacket(pMsg); //it is tainted.

  for(int i = 0; i < len; i++) {
    //it will cause OOB read for the next loop.
    ret += arr[index + 1]; //@violation DANGEROUS_USE_OF_TAINTED_VALUES

    index += packet->len;
    /* index is tainted. */
  }
}
