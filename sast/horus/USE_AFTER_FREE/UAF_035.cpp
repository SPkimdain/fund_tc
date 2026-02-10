#include <string.h>
#include <stdlib.h>

/* UAF_035 - memory function, strcat */
void UAF_035_function(char* src, char* src2, int flag) {
  char* buf = new char[256];
  if(buf == 0) {
    return;
  }

  int size = strlen(src);
  int size2 = strlen(src2);

  strncpy(buf, src, size); //It's ok.

  char* src2Copy = new char[size2 + 1];
  if(src2Copy == 0) {
    delete[] buf;
    return;
  }
  

  if(flag == 0) {
    delete[] src2Copy;
    /* Wrong control flow */
    //return;
  }

  strcat(buf, src2Copy); //@violation USE_AFTER_FREE

  delete[] buf;
  if(flag != 0) {
    delete[] src2Copy;
  }
}

