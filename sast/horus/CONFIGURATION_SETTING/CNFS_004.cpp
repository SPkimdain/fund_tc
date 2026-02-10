#include <stdlib.h>

/* CNFS_004 - simple case with lambda. */

extern void sethostid(long hostid);

int CNFS_004_function(int argc, char *argv[]) {
  

  auto&& CNFS_004_lambda = []() {
    char* data = getenv("test");    
    return data;
  };

  char* ld = CNFS_004_lambda();

  sethostid(atol(ld));  //@violation CONFIGURATION_SETTING

  return 0;
}
