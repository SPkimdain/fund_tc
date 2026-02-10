#include <stdlib.h>
#include <string.h>

/* MMTD_013 - multiple functions */
char* MMTD_013_function1(int size){
  return (char*)malloc(size);  
}

void MMTD_013_function2(char* str) {
  delete str;
}

int MMTD_013_function3(char* str, int flag) {
  if(flag == 10) {
    MMTD_013_function2(str);
    return 1;
  }
  else {
    return 0;
  }
}

void MMTD_013_function4(char* str, int flag) {
  int ret = MMTD_013_function3(str, flag);
}

void MMTD_013_function5(char* src, int size) {
  char* dst = MMTD_013_function1(size);
  if(dst == 0) {
    return;
  }

  memcpy(dst, src, size);
  
  MMTD_013_function3(dst, 0); //It's ok.

  MMTD_013_function3(dst, 10); //@violation MISMATCH.MALLOC_TO_DELETE
}

