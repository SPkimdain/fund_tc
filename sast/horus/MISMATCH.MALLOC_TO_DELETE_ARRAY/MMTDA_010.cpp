#include <stdlib.h>

/* MMTDA_010 - double pointer */
bool MMTDA_010_function1(int** ptr){
  *ptr = (int*)malloc(sizeof(int));
  if(*ptr == 0) {
    return false;
  }
  return true;
}

void MMTDA_010_function2(int** ptr){
  delete[] *ptr;
}


void MMTDA_010_function3() {
  int* value = 0;
  bool ret = MMTDA_010_function1(&value);

  if(ret == true) {
    MMTDA_010_function2(&value); //@violation MISMATCH.MALLOC_TO_DELETE_ARRAY
  }
}

