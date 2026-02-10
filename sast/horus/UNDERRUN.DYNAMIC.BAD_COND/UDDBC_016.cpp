
/* UDDBC_016 - deep fields */

struct UDDBC_016_Struct1 {
  char flag;
  int index;
};

struct UDDBC_016_Struct2 {
  UDDBC_016_Struct1 ovObj1;
};

struct UDDBC_016_Struct3{
  UDDBC_016_Struct2 ovObj2;
};

void UDDBC_016_function(int flag, int idx) {
  int* arr = new int[10];
  if(arr == 0) {
    return;
  }
  UDDBC_016_Struct3 obj;
  if(idx >= -10) {
    obj.ovObj2.ovObj1.index = idx;
  }
  else {
    obj.ovObj2.ovObj1.index = 0;
  }

  arr[obj.ovObj2.ovObj1.index] = 1234; //@violation UNDERRUN.DYNAMIC.BAD_COND

  delete[] arr;
}
