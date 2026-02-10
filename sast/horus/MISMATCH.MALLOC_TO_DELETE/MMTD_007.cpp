#include <stdlib.h>

/* MMTD_007 - return value */
char* MMTD_007_function1(int size){
  if(size < 100) {
    return (char*)malloc(sizeof(char) * size);
  }
  else {
    return 0;
  }
}

char* MMTD_007_function2(){
  char* ret = new char('x');
  return ret;
}

void MMTD_007_function3(int flag) {
  char* ptr = 0;
  
  ptr = MMTD_007_function2();
  delete ptr;
  
  ptr = 0;

  if(flag > 0) {
    ptr = MMTD_007_function1(10);
    if(ptr != 0) {
      delete ptr; //@violation MISMATCH.MALLOC_TO_DELETE
    }
  }
}

