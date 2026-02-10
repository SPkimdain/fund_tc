#include <stdlib.h>

/* MNATF_005 - Call by value2 */
void MNATF_005_function1(char* src){
  free(src);
}

char* MNATF_005_function2(int size) {
  if(size <= 1024) {
    return new char[size];
  }
  return 0;
}

void MNATF_005_function3(int size) {
  char* p = 0;

  if(size > 0 && size < 10) {
    p = MNATF_005_function2(size);
  }

  if(p != 0) {
    MNATF_005_function1(p); //@violation MISMATCH.NEW_ARRAY_TO_FREE
  }
}

