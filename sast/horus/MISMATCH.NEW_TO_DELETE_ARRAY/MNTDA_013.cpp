#include <stdlib.h>
#include <string.h>

/* MNTDA_013 - multiple functions */
char* MNTDA_013_function1(int size){
  return new char('a');
}

void MNTDA_013_function2(char* str) {
  delete[] str;
}

int MNTDA_013_function3(char* str, int flag) {
  if(flag == 10) {
    MNTDA_013_function2(str);
    return 1;
  }
  else {
    return 0;
  }
}

void MNTDA_013_function4(char* str, int flag) {
  int ret = MNTDA_013_function3(str, flag);
}

void MNTDA_013_function5(char* src, int size) {
  char* dst = MNTDA_013_function1(size);
  memcpy(dst, src, size);
  
  MNTDA_013_function3(dst, 0); //It's ok.

  MNTDA_013_function3(dst, 10); //@violation MISMATCH.NEW_TO_DELETE_ARRAY
}

