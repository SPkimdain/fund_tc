#include <stdlib.h>
#include <string.h>

/* CNFS_003 - simple case2 */

extern void sethostid(long hostid);

struct CNFS_003_Data {
  char* data;
};

void CNFS_003_function(CNFS_003_Data& obj, int flag) {
  if(flag > 10) {
    obj.data = getenv("CNFS_VAL");
  }
  return;
}

void CNFS_003_sink(long hostID, int flag) {
  if(flag < 10) {
    return;
  }

  sethostid(hostID);


  sethostid(hostID);  //Sink call.
}

int CNFS_003_function3(int x, bool check) {
  CNFS_003_Data obj;
  obj.data = 0;

  if(check == true) {
    CNFS_003_function(obj, 5);
  }
  else {
    CNFS_003_function(obj, 13);
  }

  if(obj.data == 0) {
    return 0;
  }

  char buf[256];

  strncpy(buf, obj.data, 255);

  long hostID = atol(buf);

  CNFS_003_sink(hostID, 5);  //It's ok.

  CNFS_003_sink(hostID, 20);  //@violation CONFIGURATION_SETTING

  return 0;
}
