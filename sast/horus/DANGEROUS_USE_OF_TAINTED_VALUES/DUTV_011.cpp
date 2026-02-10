
/* DUTV_011 - Support setting struct data type pointer (or object) of parameter (or return value) of function as taint case2 */

struct DUTV_011_WebPacket {
  int len;
  char data[20];
};


DUTV_011_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

int DUTV_011_function(char* pMsg) {
  DUTV_011_WebPacket* packet = getpacket(pMsg);
  /* do something */

  int lens[] = { 0, 1, 3, 5, 7 };

  int ret = *(lens + packet->len); //@violation DANGEROUS_USE_OF_TAINTED_VALUES

  return ret;
}
