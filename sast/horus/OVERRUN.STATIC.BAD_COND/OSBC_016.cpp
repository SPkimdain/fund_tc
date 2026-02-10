
/* OSBC_016 - deep fields */

struct OSBC_016_Struct1 {
  char flag;
  int index;
};

struct OSBC_016_Struct2 {
  OSBC_016_Struct1 ovObj1;
};

struct OSBC_016_Struct3{
  OSBC_016_Struct2 ovObj2;
};

void OSBC_016_function(int flag, unsigned idx) {
  int arr[10] = { 0, };
  OSBC_016_Struct3 obj;
  if(idx <= 10) {
    obj.ovObj2.ovObj1.index = idx;
  }
  else {
    obj.ovObj2.ovObj1.index = 0;
  }

  arr[obj.ovObj2.ovObj1.index] = 1234; //@violation OVERRUN.STATIC.BAD_COND
}
