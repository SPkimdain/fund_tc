
/* DUTV_014 - Support setting struct data type pointer (or object) of parameter (or return value) of function as taint / function call2 */

struct DUTV_014_WebPacket {
  int len;
  char data[20];
};


DUTV_014_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

void DUTV_014_function(int index) {

  /* do something */

  int a[10];

  a[index] = 10;

}

void DUTV_014_function2(DUTV_014_WebPacket* packet) {
  if(packet == 0) {
    return;
  }

  DUTV_014_function(packet->len);
}

int DUTV_014_function3(char* pMsg, int flag, int flag2) {
  if(pMsg == 0) {
    return 0;
  }

  DUTV_014_WebPacket* packet = getpacket(pMsg);

  switch(flag) {
  case 0:
    return 1;
  case 1:
    break;
  default:
    return 10;
  }

  if(flag && flag2 > 10) {
    DUTV_014_function2(packet); //@violation DANGEROUS_USE_OF_TAINTED_VALUES
  }

  return 0;
}

