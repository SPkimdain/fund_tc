#include <stdlib.h>
#include <string.h>

/* CNFS_002 - simple case2 */

extern void sethostid(long hostid);

struct CNFS_002_Data {
  char* data;
};

void CNFS_002_function(CNFS_002_Data& obj, int flag) {
  if(flag > 10) {
    obj.data = getenv("CNFS_VAL");
  }
  return;
}

int CNFS_002_function2(int x, bool check) {
  CNFS_002_Data obj;
  obj.data = 0;
  
  if(check == true) {
    CNFS_002_function(obj, 5);
  }
  else {
    CNFS_002_function(obj, 13);
  }

  if(obj.data == 0) {
    return 0;
  }
  
  char buf[256];

  strncpy(buf, obj.data, 255);

  long hostID = atol(buf);

  sethostid(hostID);  //@violation CONFIGURATION_SETTING
  
  return 0;
}
