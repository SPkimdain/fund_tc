
/* DUTV_022 - Support loop bound taint check case4 - while */


struct DUTV_022_WebPacket {
  int len;
  char data[20];
};

extern void hw_memcpy(char* dst, char* src, int size);

DUTV_022_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

void DUTV_022_function(int len) {
  /* do something */
  int a[10] = { 0, };

  int i = 0;
  while(i < len) {
    a[i] = i + 10;
    i++;
  }
}

void DUTV_022_function2(DUTV_022_WebPacket* packet, int flag) {
  int size = 10;
  if(flag > 10) {
    DUTV_022_function(packet->len);
  }
  else {
    DUTV_022_function(size); //It's ok.
  }
}

int DUTV_022_wrap(DUTV_022_WebPacket* obj, int flag) {


  DUTV_022_function2(obj, flag);

  return 0;
}

void DUTV_022_function4(char* pMsg, int val) {
  DUTV_022_WebPacket* packet = getpacket(pMsg);

  switch(val) {
  case 0:
    DUTV_022_wrap(packet, 0); //It's ok.
    break;

  case 1:
    DUTV_022_wrap(packet, 10); //It's ok.
    break;

  case 2:
    DUTV_022_wrap(packet, 20); //@violation DANGEROUS_USE_OF_TAINTED_VALUES
    break;
  }

}


