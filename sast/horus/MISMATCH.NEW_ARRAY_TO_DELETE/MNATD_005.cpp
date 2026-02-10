#include <stdlib.h>

/* MNATD_005 - Call by value2 */
void MNATD_005_function1(char* src){
  delete src;
}

char* MNATD_005_function2(int size) {
  if(size <= 1024) {
    return new char[size];
  }
  return 0;
}

void MNATD_005_function3(int size) {
  char* p = 0;

  if(size > 0 && size < 10) {
    p = MNATD_005_function2(size);
  }

  if(p != 0) {
    MNATD_005_function1(p); //@violation MISMATCH.NEW_ARRAY_TO_DELETE
  }
}

