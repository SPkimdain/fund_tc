#include <stdlib.h>

/* MNTF_007 - return value */
char* MNTF_007_function1(int size){
  if(size < 100) {
    return new char('1');
  }
  else {
    return 0;
  }
}

char* MNTF_007_function2(){
  char* ret = (char*)malloc(sizeof(char) * 10);
  return ret;
}

void MNTF_007_function3(int flag) {
  char* ptr = 0;
  
  ptr = MNTF_007_function2();
  free(ptr);
  
  ptr = 0;

  if(flag > 0) {
    ptr = MNTF_007_function1(10);
    if(ptr != 0) {
      free(ptr); //@violation MISMATCH.NEW_TO_FREE
    }
  }
}

