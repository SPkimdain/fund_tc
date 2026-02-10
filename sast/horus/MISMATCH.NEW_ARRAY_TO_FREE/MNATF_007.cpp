#include <stdlib.h>

/* MNATF_007 - return value */
char* MNATF_007_function1(int size){
  if(size < 100) {
    return new char[size];
  }
  else {
    return 0;
  }
}

char* MNATF_007_function2(){
  char* ret = (char*)malloc(sizeof(char) * 1);
  return ret;
}

void MNATF_007_function3(int flag) {
  char* ptr = 0;
  
  ptr = MNATF_007_function2();
  free(ptr);
  
  ptr = 0;

  if(flag > 0) {
    ptr = MNATF_007_function1(10);
    if(ptr != 0) {
      free(ptr); //@violation MISMATCH.NEW_ARRAY_TO_FREE
    }
  }
}

