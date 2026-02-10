
/* DUTV_012 - Support setting struct data type pointer (or object) of parameter (or return value) of function as taint case1 */

struct DUTV_012_WebPacket {
  int len;
  char data[20];
};


DUTV_012_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

void DUTV_012_function(char* pMsg) {
  DUTV_012_WebPacket* packet = getpacket(pMsg);
  /* do something */

  int a[10];
  
  int index = packet->len;
  index++;

  a[index] = 10; //@violation DANGEROUS_USE_OF_TAINTED_VALUES

  return;
}
