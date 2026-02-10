#include <stdlib.h>

/* MMTD_005 - Call by value2 */
void MMTD_005_function1(char* src){
  delete src;
}

char* MMTD_005_function2(int size) {
  if(size <= 1024) {
    return (char*)malloc(sizeof(char) * size);
  }
  return 0;
}

void MMTD_005_function3(int size) {
  char* p = 0;

  if(size > 0 && size < 10) {
    p = MMTD_005_function2(size);
  }

  if(p != 0) {
    MMTD_005_function1(p); //@violation MISMATCH.MALLOC_TO_DELETE
  }
}

