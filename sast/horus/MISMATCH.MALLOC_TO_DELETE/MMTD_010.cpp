#include <stdlib.h>

/* MMTD_010 - double pointer */
bool MMTD_010_function1(int** ptr){
  *ptr = (int*)malloc(sizeof(int));
  if(*ptr == 0) {
    return false;
  }
  return true;
}

void MMTD_010_function2(int** ptr){
  delete *ptr;
}


void MMTD_010_function3() {
  int* value = 0;
  bool ret = MMTD_010_function1(&value);

  if(ret == true) {
    MMTD_010_function2(&value); //@violation MISMATCH.MALLOC_TO_DELETE
  }
}

