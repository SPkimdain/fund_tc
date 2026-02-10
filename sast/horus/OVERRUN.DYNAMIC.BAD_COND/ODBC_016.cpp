
/* ODBC_016 - deep fields */

struct ODBC_016_Struct1 {
  char flag;
  int index;
};

struct ODBC_016_Struct2 {
  ODBC_016_Struct1 ovObj1;
};

struct ODBC_016_Struct3{
  ODBC_016_Struct2 ovObj2;
};

void ODBC_016_function(int flag, unsigned idx) {
  int* arr = new int[10];
  if(arr == 0) {
    return;
  }
  ODBC_016_Struct3 obj;
  if(idx <= 10) {
    obj.ovObj2.ovObj1.index = idx;
  }
  else {
    obj.ovObj2.ovObj1.index = 0;
  }

  arr[obj.ovObj2.ovObj1.index] = 1234; //@violation OVERRUN.DYNAMIC.BAD_COND

  delete[] arr;
}
