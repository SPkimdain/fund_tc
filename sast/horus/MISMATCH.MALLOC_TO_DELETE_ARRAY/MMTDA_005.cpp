#include <stdlib.h>

/* MMTDA_005 - Call by value2 */
void MMTDA_005_function1(char* src){
  delete[] src;
}

char* MMTDA_005_function2(int size) {
  if(size <= 1024) {
    return (char*)malloc(sizeof(char) * size);
  }
  return 0;
}

void MMTDA_005_function3(int size) {
  char* p = 0;

  if(size > 0 && size < 10) {
    p = MMTDA_005_function2(size);
  }

  if(p != 0) {
    MMTDA_005_function1(p); //@violation MISMATCH.MALLOC_TO_DELETE_ARRAY
  }
}

