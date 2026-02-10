
/* DUTV_028 - Support setting function parameter as sink point, simple case1 */

struct DUTV_028_WebPacket {
  int len;
  char data[20];
};

extern void hw_memcpy(char* dst, char* src, int size);

DUTV_028_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

void DUTV_028_function(char* pMsg, int len, int* arr) {
  int ret = 0;
  int index = 0;

  DUTV_028_WebPacket* packet = getpacket(pMsg); //it is tainted.

  for(int i = 0; i < len; i++) {
    ret += arr[i]; //it's ok.

    if(i == 0) {
      ret += arr[index] + 2; //it's ok. if i != 0 can't come here.
    }
    
    //it will cause OOB read for the next loop.
    ret += arr[index]; //@violation DANGEROUS_USE_OF_TAINTED_VALUES
    
    index += packet->len;
    /* index is tainted. */
  }
}
