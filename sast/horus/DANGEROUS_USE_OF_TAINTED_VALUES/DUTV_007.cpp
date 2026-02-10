
/* DUTV_007 - Support setting function parameter as sink point, deep call stack */

struct DUTV_007_WebPacket {
  int len;
  char data[20];
};

extern void hw_memcpy(char* dst, char* src, int size);

DUTV_007_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

void DUTV_007_function(int len, char* src) {
  /* do something */
  char dst[10];

  hw_memcpy(dst, src, len); /* passing taint variable to taint sink */

}

int DUTV_007_wrap(int len, char* src) {
  if(src == 0) {
    return 1;
  }

  DUTV_007_function(len, src);

  return 0;
}


int DUTV_007_function2(DUTV_007_WebPacket& obj) {
  return DUTV_007_wrap(obj.len, obj.data);
}

void DUTV_008_wrap2(DUTV_007_WebPacket* webPacket) {
  int ret = DUTV_007_function2(*webPacket);

  return;
}

int DUTV_007_function4(char* pMsg, int flag) {
  DUTV_007_WebPacket* packet = getpacket(pMsg);
  if(packet == 0) {
    return 0;
  }

  int ret = 0;

  switch(flag) {
  case 0:
    ret++;
    break;
  case 2:
    DUTV_008_wrap2(packet);  //@violation DANGEROUS_USE_OF_TAINTED_VALUES
    break;
  default:
    ret += 2;
    break;
  }
  

  return ret;
}
