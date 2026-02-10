
/* DUTV_024 - Support pointer offset taint check */

struct DUTV_024_WebPacket {
  int len;
  char data[20];
};


DUTV_024_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

int DUTV_024_function(char* pMsg) {
  DUTV_024_WebPacket* packet = getpacket(pMsg);
  /* do something */

  int lens[] = { 0, 1, 3, 5, 7 };

  int* dest = lens + packet->len; //It's ok.

  /* pointer dereference + offset is tainted. */
  int ret = *dest; //@violation DANGEROUS_USE_OF_TAINTED_VALUES

  return ret;
}
