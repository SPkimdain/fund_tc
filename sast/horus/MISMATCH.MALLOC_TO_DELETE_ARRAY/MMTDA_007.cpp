#include <stdlib.h>

/* MMTDA_007 - return value */
char* MMTDA_007_function1(int size){
  if(size < 100) {
    return (char*)malloc(sizeof(char) * size);
  }
  else {
    return 0;
  }
}

char* MMTDA_007_function2(){
  char* ret = new char[10];
  return ret;
}

void MMTDA_007_function3(int flag) {
  char* ptr = 0;
  
  ptr = MMTDA_007_function2();
  delete[] ptr;
  
  ptr = 0;

  if(flag > 0) {
    ptr = MMTDA_007_function1(10);
    if(ptr != 0) {
      delete[] ptr; //@violation MISMATCH.MALLOC_TO_DELETE_ARRAY
    }
  }
}

