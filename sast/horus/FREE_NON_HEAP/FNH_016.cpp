#include <string.h>

/* FNH_016 - array */
void FNH_016_function1(char* src) {
  delete[] src;
}

void FNH_016_function2(char* src, int size, int flag) {
  char* str1 = new char[size + 1];
  if(str1 == 0) {
    return;
  }

  char str2[256];

  if(flag > 0) {
    strncpy(str1, src, size);
    FNH_016_function1(str1); //It's ok.
  }
  else {
    strncpy(str2, src, size);
    FNH_016_function1(str2); //@violation FREE_NON_HEAP

    delete[] str1;
  }
}


