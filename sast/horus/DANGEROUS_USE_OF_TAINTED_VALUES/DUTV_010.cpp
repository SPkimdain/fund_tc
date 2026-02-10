
/* DUTV_010 - Support setting struct data type pointer (or object) of parameter (or return value) of function as taint case2 */

struct DUTV_010_WebPacket {
  int len;
  char data[20];
};


DUTV_010_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

void DUTV_010_function(char* pMsg) {
  DUTV_010_WebPacket* packet = getpacket(pMsg);
  /* do something */

  int a[10];

  a[packet->len + 1] = 10; //@violation DANGEROUS_USE_OF_TAINTED_VALUES

}
