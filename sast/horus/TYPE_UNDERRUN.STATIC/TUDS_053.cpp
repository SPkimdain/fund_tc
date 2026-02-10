
/* TUDS_053 - deep fiedls */
struct TUDS_053_Struct1 {
  char flag;
  int index;
};

struct TUDS_053_Struct2 {
  TUDS_053_Struct1 ovObj1;
};

struct TUDS_053_Struct3{
  TUDS_053_Struct2 ovObj2;
  int arr[10];
};

void TUDS_053_function(int flag) {
  TUDS_053_Struct3 obj;
  if(flag > 10) {
    obj.ovObj2.ovObj1.index = 5;
  }
  else {
    obj.ovObj2.ovObj1.index = -10;
  }

  obj.arr[obj.ovObj2.ovObj1.index] = 1234; //@violation TYPE_UNDERRUN.STATIC
}
