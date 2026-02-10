#include <stdlib.h>

/* LM_014 - call by reference */
void LM_014_function1(int** ptr, int** ptr2) {
  *ptr = (int*)malloc(4);
  *ptr2 = (int*)malloc(8);
}

int* LM_014_function2() {
  int data = 10;

  int* pData = 0;
  int* pData2 = 0;

  LM_014_function1(&pData, &pData2);

  return pData;
  //pData2 is leaked.
} //@violation LEAK.MEMORY

