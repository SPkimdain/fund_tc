
/* DUTV_009 - Support setting struct data type pointer (or object) of parameter (or return value) of function as taint case1 */

struct DUTV_009_WebPacket {
  int len;
  char data[20];
};


DUTV_009_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

void DUTV_009_function(char* pMsg) {
  DUTV_009_WebPacket* packet = getpacket(pMsg);
  /* do something */
  
  int a[10];

  a[packet->len] = 10; //@violation DANGEROUS_USE_OF_TAINTED_VALUES

}
