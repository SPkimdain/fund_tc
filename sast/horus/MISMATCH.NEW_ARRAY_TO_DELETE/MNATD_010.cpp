#include <stdlib.h>

/* MNATD_010 - double pointer */
bool MNATD_010_function1(int** ptr){
  *ptr = new int[256];
  if(*ptr == 0) {
    return false;
  }
  return true;
}

void MNATD_010_function2(int** ptr){
  delete *ptr;
}


void MNATD_010_function3() {
  int* value = 0;
  bool ret = MNATD_010_function1(&value);

  MNATD_010_function2(&value); //@violation MISMATCH.NEW_ARRAY_TO_DELETE

}

