
/* DUTV_031 - sanitize / compare case3 */

struct DUTV_031_WebPacket {
  int len;
  char data[20];
};

extern void hw_memcpy(char* dst, char* src, int size);

DUTV_031_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

void DUTV_031_function(char* pMsg, int len, int* arr) {
  int ret = 0;
  int index = 0;

  DUTV_031_WebPacket* packet = getpacket(pMsg); //it is tainted.

  for(int i = 0; i < len; i++) {
    ret += arr[i]; //it's ok.

    //it will cause OOB read for the next loop.
    ret += arr[index]; //it's ok.
    
    index += packet->len;
    /* index is tainted. but it's ok. see line 29. */

    /* sanitize */
    index = index > 100 ? 100 : index;
  }
}


void DUTV_031_function2(char* pMsg, int len, int* arr, int flag) {
  int ret = 0;
  int index = 0;

  DUTV_031_WebPacket* packet = getpacket(pMsg); //it is tainted.

  for(int i = 0; i < len; i++) {
    //it will cause OOB read for the next loop.
    if(flag == 1) {
      ret += arr[index + 1]; //it's ok. sanitize control flow.
    }
    else {
      ret += arr[index + 5]; //@violation DANGEROUS_USE_OF_TAINTED_VALUES
    }

    index += packet->len;
    /* index is tainted. */

    if(flag == 1) {
      /* sanitize if flag == 1 */
      index = index > 100 ? 100 : index;
    }
  }
}
