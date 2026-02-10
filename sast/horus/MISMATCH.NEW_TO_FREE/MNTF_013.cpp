#include <stdlib.h>
#include <string.h>

/* MNTF_013 - multiple functions */
char* MNTF_013_function1(int size){
  return new char('a');
}

void MNTF_013_function2(char* str) {
  free(str);
}

int MNTF_013_function3(char* str, int flag) {
  if(flag == 10) {
    MNTF_013_function2(str);
    return 1;
  }
  else {
    return 0;
  }
}

void MNTF_013_function4(char* str, int flag) {
  int ret = MNTF_013_function3(str, flag);
}

void MNTF_013_function5(char* src, int size) {
  char* dst = MNTF_013_function1(size);
  memcpy(dst, src, size);
  
  MNTF_013_function3(dst, 0); //It's ok.

  MNTF_013_function3(dst, 10); //@violation MISMATCH.NEW_TO_FREE
}

