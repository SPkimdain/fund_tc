#include <stdlib.h>

/* CNFS_001 - simple case */

extern void sethostid(long hostid);

int CNFS_001_function(int argc, char *argv[]) {
  char* data = getenv("test");

  sethostid(atol(data));  //@violation CONFIGURATION_SETTING

  return 0;
}
