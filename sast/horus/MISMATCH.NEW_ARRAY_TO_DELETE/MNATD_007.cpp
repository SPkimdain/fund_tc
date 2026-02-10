#include <stdlib.h>

/* MNATD_007 - return value */
char* MNATD_007_function1(int size){
  if(size < 100) {
    return new char[10];
  }
  else {
    return 0;
  }
}

char* MNATD_007_function2(){
  char* ret = new char('x');
  return ret;
}

void MNATD_007_function3(int flag) {
  char* ptr = 0;
  
  ptr = MNATD_007_function2();
  delete ptr;
  
  ptr = 0;

  if(flag > 0) {
    ptr = MNATD_007_function1(10);
    if(ptr != 0) {
      delete ptr; //@violation MISMATCH.NEW_ARRAY_TO_DELETE
    }
  }
}

