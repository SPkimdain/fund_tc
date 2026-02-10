
/* DUTV_002 - Support setting function parameter as sink point, simple case2 */

struct DUTV_002_WebPacket {
  int len;
  char data[20];
};

extern void hw_memcpy(char* dst, char* src, int size);

DUTV_002_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

void DUTV_002_function(DUTV_002_WebPacket* packet) {
  if(packet != 0) {
    /* do something */
    char dst[10];

    /* passing taint variable to taint sink */
    hw_memcpy(dst, packet->data, packet->len);

  }
}

DUTV_002_WebPacket* DUTV_002_passingTaint(int flag) {
  char* msg = "test";
  DUTV_002_WebPacket* packet = getpacket(msg);

  if(flag > 10) {
    return packet;
  }
  else {
    return 0;
  }
}


void DUTV_002_function2(bool taintCheck) {
  if(taintCheck == false) {
    DUTV_002_WebPacket* packet = DUTV_002_passingTaint(4);

    DUTV_002_function(packet); //It's ok.

    return;
  }
  else {

    DUTV_002_WebPacket* packet2 = DUTV_002_passingTaint(12);

    DUTV_002_function(packet2); //@violation DANGEROUS_USE_OF_TAINTED_VALUES

  }  
}
