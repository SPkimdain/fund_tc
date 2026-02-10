#include <stdlib.h>
#include <string.h>

/* MMTDA_013 - multiple functions */
char* MMTDA_013_function1(int size){
  return (char*)malloc(size);  
}

void MMTDA_013_function2(char* str) {
  delete[] str;
}

int MMTDA_013_function3(char* str, int flag) {
  if(flag == 10) {
    MMTDA_013_function2(str);
    return 1;
  }
  else {
    return 0;
  }
}

void MMTDA_013_function4(char* str, int flag) {
  int ret = MMTDA_013_function3(str, flag);
}

void MMTDA_013_function5(char* src, int size) {
  char* dst = MMTDA_013_function1(size);
  if(dst == 0) {
    return;
  }

  memcpy(dst, src, size);
  
  MMTDA_013_function3(dst, 0); //It's ok.

  MMTDA_013_function3(dst, 10); //@violation MISMATCH.MALLOC_TO_DELETE_ARRAY
}

