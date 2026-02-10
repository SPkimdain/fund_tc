
/* UDSBC_016 - deep fields */

struct UDSBC_016_Struct1 {
  char flag;
  int index;
};

struct UDSBC_016_Struct2 {
  UDSBC_016_Struct1 ovObj1;
};

struct UDSBC_016_Struct3{
  UDSBC_016_Struct2 ovObj2;
};

void UDSBC_016_function(int flag, int idx) {
  int arr[10] = { 0, };
  UDSBC_016_Struct3 obj;
  if(idx >= -10) {
    obj.ovObj2.ovObj1.index = idx;
  }
  else {
    obj.ovObj2.ovObj1.index = 0;
  }

  arr[obj.ovObj2.ovObj1.index] = 1234; //@violation UNDERRUN.STATIC.BAD_COND
}
