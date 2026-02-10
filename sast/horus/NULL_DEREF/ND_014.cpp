

/* ND_014 - call by reference */
void ND_014_function1(int** ptr, int** ptr2) {
  int* pValue;
  int* pValue2;

  int ret = 0;

  pValue = *ptr;
  pValue2 = *ptr2;

  ret += *pValue; //No Problem

  ret += *pValue2; 
}

void ND_014_function2() {
  int data = 10;

  int* pData;
  int* pData2;

  pData = &data;
  pData2 = 0;

  ND_014_function1(&pData, &pData2);	//@violation NULL_DEREF
}

