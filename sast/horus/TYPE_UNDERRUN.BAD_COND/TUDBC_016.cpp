
/* TUDBC_016 - deep fields */
struct TUDBC_016_Struct1 {
  char flag;
  int index;
};

struct TUDBC_016_Struct2 {
  TUDBC_016_Struct1 ovObj1;
};

struct TUDBC_016_Struct3{
  TUDBC_016_Struct2 ovObj2;
  int arr[10];
};

void TUDBC_016_function(int flag, int idx) {
  TUDBC_016_Struct3 obj;
  if(idx >= -1) {
    obj.ovObj2.ovObj1.index = idx;
  }
  else {
    obj.ovObj2.ovObj1.index = 0;
  }

  obj.arr[obj.ovObj2.ovObj1.index] = 1234; //@violation TYPE_UNDERRUN.BAD_COND
}
