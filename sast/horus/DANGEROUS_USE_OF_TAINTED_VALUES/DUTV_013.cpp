
/* DUTV_013 - Support setting struct data type pointer (or object) of parameter (or return value) of function as taint / function call1 */

struct DUTV_013_WebPacket {
  int len;
  char data[20];
};


DUTV_013_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

void DUTV_013_function(DUTV_013_WebPacket* packet) {
  
  /* do something */

  int a[10];

  a[packet->len] = 10;

}

void DUTV_013_function2(char* pMsg) {
  if(pMsg == 0) {
    return;
  }

  DUTV_013_WebPacket* packet = getpacket(pMsg);

  DUTV_013_function(packet); //@violation DANGEROUS_USE_OF_TAINTED_VALUES
}

