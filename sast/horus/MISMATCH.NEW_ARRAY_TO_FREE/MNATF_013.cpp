#include <stdlib.h>
#include <string.h>

/* MNATF_013 - multiple functions */
char* MNATF_013_function1(int size){
  return new char[size];
}

void MNATF_013_function2(char* str) {
  free(str);
}

int MNATF_013_function3(char* str, int flag) {
  if(flag == 10) {
    MNATF_013_function2(str);
    return 1;
  }
  else {
    return 0;
  }
}

void MNATF_013_function4(char* str, int flag) {
  int ret = MNATF_013_function3(str, flag);
}

void MNATF_013_function5(char* src, int size) {
  char* dst = MNATF_013_function1(size);
  memcpy(dst, src, size);
  
  MNATF_013_function3(dst, 0); //It's ok.

  MNATF_013_function3(dst, 10); //@violation MISMATCH.NEW_ARRAY_TO_FREE
}

