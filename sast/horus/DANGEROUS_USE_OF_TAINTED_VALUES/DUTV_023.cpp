
/* DUTV_023 - Support loop bound taint check case3 */


struct DUTV_023_WebPacket {
  int len;
  char data[20];
};

extern void hw_memcpy(char* dst, char* src, int size);

DUTV_023_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

void DUTV_023_function(int len) {
  /* do something */
  int a[10] = { 0, };

  int i = 0;
  do {
    a[i] = i + 10;
    i++;
  } while(i < len);
}

void DUTV_023_function2(DUTV_023_WebPacket* packet, int flag) {
  int size = 10;
  if(flag > 10) {
    DUTV_023_function(packet->len);
  }
  else {
    DUTV_023_function(size); //It's ok.
  }
}

int DUTV_023_wrap(DUTV_023_WebPacket* obj, int flag) {


  DUTV_023_function2(obj, flag);

  return 0;
}

void DUTV_023_function4(char* pMsg, int val) {
  DUTV_023_WebPacket* packet = getpacket(pMsg);

  switch(val) {
  case 0:
    DUTV_023_wrap(packet, 0); //It's ok.
    break;

  case 1:
    DUTV_023_wrap(packet, 10); //It's ok.
    break;

  case 2:
    DUTV_023_wrap(packet, 20); //@violation DANGEROUS_USE_OF_TAINTED_VALUES
    break;
  }

}


