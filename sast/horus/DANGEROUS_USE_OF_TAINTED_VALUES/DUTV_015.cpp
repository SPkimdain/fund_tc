
/* DUTV_015 - Support setting struct data type pointer (or object) of parameter (or return value) of function as taint / function call3 */

struct DUTV_015_WebPacket {
  int len;
  char data[20];
};


DUTV_015_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

int DUTV_015_function(int index) {

  /* do something */

  int a[10];

  a[index] = 10;


  return a[index];
}

void DUTV_015_function2(DUTV_015_WebPacket* packet) {
  if(packet == 0) {
    return;
  }

  int index = packet->len;

  DUTV_015_function(index);
}

DUTV_015_WebPacket* DUTV_015_getPacket(char* pMsg) {
  DUTV_015_WebPacket* packet = getpacket(pMsg);

  return packet;
}

int DUTV_015_function3(char* pMsg, int flag, int flag2) {
  if(pMsg == 0) {
    return 0;
  }

  DUTV_015_WebPacket* packet = DUTV_015_getPacket(pMsg);
  if(packet != 0 && flag > 1 && flag2 > 100) {  
    DUTV_015_function2(packet); //@violation DANGEROUS_USE_OF_TAINTED_VALUES
  }

  return 0;
}

