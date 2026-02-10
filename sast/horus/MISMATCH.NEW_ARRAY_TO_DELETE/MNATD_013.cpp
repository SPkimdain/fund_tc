#include <stdlib.h>
#include <string.h>

/* MNATD_013 - multiple functions */
char* MNATD_013_function1(int size){
  return new char[size];
}

void MNATD_013_function2(char* str) {
  delete str;
}

int MNATD_013_function3(char* str, int flag) {
  if(flag == 10) {
    MNATD_013_function2(str);
    return 1;
  }
  else {
    return 0;
  }
}

void MNATD_013_function4(char* str, int flag) {
  int ret = MNATD_013_function3(str, flag);
}

void MNATD_013_function5(char* src, int size) {
  char* dst = MNATD_013_function1(size);
  memcpy(dst, src, size);
  
  MNATD_013_function3(dst, 0); //It's ok.

  MNATD_013_function3(dst, 10); //@violation MISMATCH.NEW_ARRAY_TO_DELETE
}

