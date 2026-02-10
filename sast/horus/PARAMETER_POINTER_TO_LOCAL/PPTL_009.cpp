

/* PPTL_009 - call by reference */
int* PPTL_009_function1(int** ptr, int** ptr2) {
  int* pValue;
  int* pValue2;

  int ret = 0;

  pValue = *ptr;
  pValue2 = *ptr2;

  ret += *pValue; //No Problem

  return pValue;
}

void PPTL_009_function2(int check, int& data2, int** out) {
  int data = 10;

  int* pData;
  int* pData2;

  pData = &data;
  pData2 = &data2;

  if(check == 1) {
    int* ret = PPTL_009_function1(&pData, &pData2);

    *out = ret; //@violation PARAMETER_POINTER_TO_LOCAL
  }
  else {
    int* ret = PPTL_009_function1(&pData2, &pData);

    *out = ret; //It's ok.
  }
}

