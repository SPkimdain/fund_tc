#include <stdlib.h>

/* MNTDA_005 - Call by value2 */
void MNTDA_005_function1(char* src){
  delete[] src;
}

char* MNTDA_005_function2(int size) {
  if(size <= 1024) {
    return new char('1');
  }
  return 0;
}

void MNTDA_005_function3(int size) {
  char* p = 0;

  if(size > 0 && size < 10) {
    p = MNTDA_005_function2(size);
  }

  if(p != 0) {
    MNTDA_005_function1(p); //@violation MISMATCH.NEW_TO_DELETE_ARRAY
  }
}

