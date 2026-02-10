

/* DBZ_014 - call by reference */
void DBZ_014_function1(int** ptr, int** ptr2) {
  int* pValue;
  int* pValue2;

  int ret = 0;

  pValue = *ptr;
  pValue2 = *ptr2;

  ret += 100 / *pValue; //No Problem

  ret += 100 / *pValue2; // DIV_BY_ZERO
}

void DBZ_014_function2() {
  int data = 10;
  int data2 = 0;

  int* pData;
  int* pData2;

  pData = &data;
  pData2 = &data2;

  DBZ_014_function1(&pData, &pData2); //@violation DIV_BY_ZERO
}

