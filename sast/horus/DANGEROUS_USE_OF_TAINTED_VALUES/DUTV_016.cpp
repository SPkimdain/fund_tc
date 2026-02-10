
/* DUTV_016 - Support setting struct data type pointer (or object) of parameter (or return value) of function as taint / function call4 */

struct DUTV_016_WebPacket {
  int len;
  char data[20];
};


DUTV_016_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

int DUTV_016_function(int index1, int index2, int flag) {

  if(flag > 10) {
    return index1;
  }
  else {
    return index2;
  }
}

DUTV_016_WebPacket* DUTV_016_getPacket(char* pMsg) {
  DUTV_016_WebPacket* packet = getpacket(pMsg);

  return packet;
}

int DUTV_016_function3(char* pMsg, int flag, int flag2, int idx) {
  if(pMsg == 0) {
    return 0;
  }

  DUTV_016_WebPacket* packet = DUTV_016_getPacket(pMsg);
  if(packet != 0 && flag > 1 && flag2 > 100) {
    int arr[10] = { 0, };
    arr[DUTV_016_function(packet->len, idx, 5)] = 20; //It's ok.

    arr[DUTV_016_function(packet->len, idx, 15)] = 30; //@violation DANGEROUS_USE_OF_TAINTED_VALUES
  }

  return 0;
}

