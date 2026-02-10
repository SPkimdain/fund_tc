

/* RF_009 - call by reference */
int* RF_009_function1(int** ptr, int** ptr2) {
  int* pValue;
  int* pValue2;

  int ret = 0;

  pValue = *ptr;
  pValue2 = *ptr2;

  ret += *pValue; //No Problem

  return pValue;
}

int* RF_009_function2(int check, int& data2) {
  int* data = new int(10);

  int* pData;
  int* pData2;

  pData = data;
  pData2 = &data2;

  if(check == 1) {
    int* ret = RF_009_function1(&pData, &pData2);

    delete data;

    return ret; //@violation RETURN_FREE
  }
  else {
    int* ret = RF_009_function1(&pData2, &pData);

    delete data;

    return ret; //It's ok.
  }
}

