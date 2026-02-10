

/* TUDS_014 - call by reference */
struct TUDS_014_Struct {
  TUDS_014_Struct() : i(0), c(0), l(0) {
    pData[0] = 0;
    pData[1] = 0;
    pData[2] = 0;
    pData2[0] = 0;
    pData2[1] = 0;
    pData2[2] = 0;
  }
  int i;
  char c;
  long l;
  int pData[3];
  int pData2[3];
};

void TUDS_014_function1(int* ptr, int* ptr2) {
  int* pValue = 0;
  int* pValue2 = 0;

  int ret = 0;

  pValue = ptr;
  pValue2 = ptr2;
  ret += pValue[1]; //No Problem  
  ret += pValue2[-4]; //TYPE_UNDERRUN.STATIC
}

void TUDS_014_function2() {
  TUDS_014_Struct sb;

  TUDS_014_function1((int*)sb.pData, (int*)sb.pData2);	//@violation TYPE_UNDERRUN.STATIC
}
