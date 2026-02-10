#include <string.h>
#include <stdlib.h>

/* UAF_041 - memory function, strcat, multiple */
void UAF_041_function1(char* dst, char* src, int flag) {
  if(flag > 0) {
    strcat(dst, src);
  }
}

void UAF_041_function2(char* src, int flag) {
  char* buf = new char[256];
  if(buf == 0) {
    return;
  }

  char src2[] = "1324";
  char src3[] = "4567";

  int size = strlen(src);

  strncpy(buf, src, size); //It's ok.

  UAF_041_function1(buf, src2, 10); //It's ok.

  delete[] buf;

  UAF_041_function1(buf, src3, 10); //@violation USE_AFTER_FREE
}


