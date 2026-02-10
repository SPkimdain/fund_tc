
/* TOS_053 - deep fiedls */
struct TOS_053_Struct1 {
  char flag;
  int index;
};

struct TOS_053_Struct2 {
  TOS_053_Struct1 ovObj1;
};

struct TOS_053_Struct3{
  TOS_053_Struct2 ovObj2;
  int arr[10];
};

void TOS_053_function(int flag) {
  TOS_053_Struct3 obj;
  if(flag > 10) {
    obj.ovObj2.ovObj1.index = 5;
  }
  else {
    obj.ovObj2.ovObj1.index = 10;
  }

  obj.arr[obj.ovObj2.ovObj1.index] = 1234; //@violation TYPE_OVERRUN.STATIC
}
