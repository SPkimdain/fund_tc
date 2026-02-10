
/* TOBC_016 - deep fields */
struct TOBC_016_Struct1 {
  char flag;
  int index;
};

struct TOBC_016_Struct2 {
  TOBC_016_Struct1 ovObj1;
};

struct TOBC_016_Struct3{
  TOBC_016_Struct2 ovObj2;
  int arr[10];
};

void TOBC_016_function(int flag, unsigned idx) {
  TOBC_016_Struct3 obj;
  if(idx <= 10) {
    obj.ovObj2.ovObj1.index = idx;
  }
  else {
    obj.ovObj2.ovObj1.index = 0;
  }

  obj.arr[obj.ovObj2.ovObj1.index] = 1234; //@violation TYPE_OVERRUN.BAD_COND
}
