

/* UN_014 - call by reference */
void UN_014_function1(int** ptr, int** ptr2) {
  int* pValue;
  int* pValue2;

  int ret = 0;

  pValue = *ptr;
  pValue2 = *ptr2;

  ret += *pValue; //No Problem

  ret += *pValue2; 
}

void UN_014_function2() {
  int data1 = 10;
  int data2;

  int* pData = &data1;
  int* pData2 = &data2;

  UN_014_function1(&pData, &pData2);	//@violation UNINIT
}

