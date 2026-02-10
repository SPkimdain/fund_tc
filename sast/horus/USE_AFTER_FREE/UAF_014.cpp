#include <stdlib.h>

/* UAF_014 - call by reference */
void UAF_014_function1(int** ptr, int** ptr2) {
  int* pValue;
  int* pValue2;

  int ret = 0;

  pValue = *ptr; //It's ok.
  pValue2 = *ptr2; 

}

void UAF_014_function2() {
  int data = 10;

  int* pData;
  int* pData2;

  pData = (int*)malloc(4);
  
  if(pData == 0) {
    return;
  }
  
  pData2 = (int*)malloc(2);
  
  if(pData2 == 0) {
    free(pData);
    return;
  }

  *pData = 10;
  *pData2 = 5;
  free(pData2);

  UAF_014_function1(&pData, &pData2); //@violation USE_AFTER_FREE

  free(pData);
}

