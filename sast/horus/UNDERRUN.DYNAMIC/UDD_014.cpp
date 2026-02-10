

/* UDD_014 - call by reference */
void UDD_014_function1(int* ptr, int* ptr2) {
  int* pValue = 0;
  int* pValue2 = 0;

  int ret = 0;

  pValue = ptr;
  pValue2 = ptr2;
  ret += pValue[1]; //No Problem  
  ret += pValue2[-4]; //UNDERRUN.DYNAMIC
}

void UDD_014_function2() {
  int* pData = new int[3]();
  if(pData == 0) {
    return;
  }
  int* pData2 = new int[3]();
  if(pData2 == 0) {
    return;
  }

  UDD_014_function1((int*)pData, (int*)pData2);	//@violation UNDERRUN.DYNAMIC

  delete[] pData;
  delete[] pData2;
}
